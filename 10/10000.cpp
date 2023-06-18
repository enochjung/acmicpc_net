#include <cstdio>
#include <algorithm>
#include <vector>

struct segment {
    int start, end;
};

class segment_tree {
   private:
    int n;
    std::vector<bool> tree;

    bool set(int idx, int start, int end, int left, int right) {
        if (start <= left && right <= end)
            tree[idx] = true;
        else if (!tree[idx] && !(right <= start || end <= left)) {
            int mid = (left + right) / 2;
            tree[idx] = set(idx * 2 + 0, start, end, left, mid) &
                        set(idx * 2 + 1, start, end, mid, right);
        }
        return tree[idx];
    }

    bool get(int idx, int start, int end, int left, int right) const {
        if (right <= start || end <= left) return true;
        if (start <= left && right <= end) return tree[idx];

        int mid = (left + right) / 2;
        return get(idx * 2 + 0, start, end, left, mid) &&
               get(idx * 2 + 1, start, end, mid, right);
    }

   public:
    segment_tree(int n) {
        for (this->n = 1; this->n < n; this->n <<= 1)
            ;
        tree.resize(this->n * 2 + 1, 0);
    }

    void fill(int start, int end) { set(1, start, end, 0, n); }

    bool is_filled(int start, int end) const {
        return get(1, start, end, 0, n);
    }
};

std::vector<segment> compress_coordinate(const std::vector<segment> &src) {
    int n = (int)src.size();

    std::vector<int> coordinates(n * 2);
    for (int i = 0; i < n; ++i) {
        coordinates[i * 2 + 0] = src[i].start;
        coordinates[i * 2 + 1] = src[i].end;
    }

    std::sort(coordinates.begin(), coordinates.end());
    coordinates.erase(std::unique(coordinates.begin(), coordinates.end()),
                      coordinates.end());

    std::vector<segment> compressed(n);
    for (int i = 0; i < n; ++i) {
        int start_idx = (std::lower_bound(coordinates.begin(),
                                          coordinates.end(), src[i].start) -
                         coordinates.begin());
        int end_idx = (std::lower_bound(coordinates.begin(), coordinates.end(),
                                        src[i].end) -
                       coordinates.begin());
        compressed[i] = {start_idx, end_idx};
    }

    return compressed;
}

int get_n_of_region(const std::vector<segment> &segments) {
    std::vector<segment> compressed = compress_coordinate(segments);
    std::sort(compressed.begin(), compressed.end(),
              [](const segment &lhs, const segment &rhs) {
                  return lhs.end - lhs.start < rhs.end - rhs.start;
              });

    int n = (int)compressed.size();
    segment_tree st = segment_tree(n * 2);
    int res = n + 1;

    for (int i = 0; i < n; ++i) {
        const segment &now = compressed[i];
        if (st.is_filled(now.start, now.end))
            ++res;
        else
            st.fill(now.start, now.end);
    }
    return res;
}

int main() {
    int n;

    scanf("%d", &n);
    std::vector<segment> circles(n);

    for (int i = 0; i < n; i++) {
        int x, r;
        scanf("%d %d", &x, &r);
        circles[i].start = x - r;
        circles[i].end = x + r;
    }

    printf("%d\n", get_n_of_region(circles));
    return 0;
}
