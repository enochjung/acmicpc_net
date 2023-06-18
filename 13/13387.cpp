#include <cstdio>
#include <algorithm>
#include <vector>

class segment_tree {
   private:
    struct node {
        int val, idx;
    };

    int n;
    std::vector<node> tree;

    void set(int idx, int left, int right, node data) {
        if (data.idx < left || right <= data.idx) return;
        if (left + 1 == right) {
            tree[idx] = data;
            return;
        }

        if (tree[idx].val < data.val) tree[idx] = data;
        int mid = (left + right) / 2;
        set(idx * 2 + 0, left, mid, data);
        set(idx * 2 + 1, mid, right, data);
    }

    node get(int idx, int start, int end, int left, int right) const {
        if (end <= left || right <= start) return {0, 0};
        if (start <= left && right <= end) return tree[idx];

        int mid = (left + right) / 2;
        node ln = get(idx * 2 + 0, start, end, left, mid);
        node rn = get(idx * 2 + 1, start, end, mid, right);
        return ln.val >= rn.val ? ln : rn;
    }

   public:
    segment_tree(int size) {
        for (n = 1; n < size; n <<= 1)
            ;
        tree.resize(n * 2);
    }

    void set(int idx, int val) { set(1, 0, n, {val, idx}); }

    int get(int start, int end) const { return get(1, start, end, 0, n).idx; }
};

int get_maximum_water(const std::vector<int> &walls, const segment_tree &st,
                      int start, int end) {
    if (start + 2 == end) return std::min(walls[start], walls[start + 1]);

    int highest_wall_idx = st.get(start + 1, end - 1);
    int highest_wall_height = walls[highest_wall_idx];
    int width = end - start - 1;
    int height = std::max(0, std::min(walls[start] - highest_wall_height,
                                      walls[end - 1] - highest_wall_height));
    int water_above = width * height;

    int water_below =
        std::max(get_maximum_water(walls, st, start, highest_wall_idx + 1),
                 get_maximum_water(walls, st, highest_wall_idx, end));
    return water_above + water_below;
}

int get_answer(const std::vector<int> &walls) {
    int n = (int)walls.size();
    segment_tree st(n);

    for (int i = 0; i < n; ++i) st.set(i, walls[i]);

    return get_maximum_water(walls, st, 0, n);
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        std::vector<int> a;

        scanf("%d", &n);
        a.resize(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        printf("%d\n", get_answer(a));
    }

    return 0;
}
