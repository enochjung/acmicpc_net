#include <cstdio>
#include <algorithm>
#include <vector>

class segment_tree {
   private:
    struct node {
        long long sum, lazy;
    };

    int n;
    std::vector<node> tree;

    void update_sum(int idx, int width) {
        tree[idx].sum += tree[idx].lazy * width;
        if (idx < n) {
            tree[idx * 2 + 0].lazy += tree[idx].lazy;
            tree[idx * 2 + 1].lazy += tree[idx].lazy;
        }
        tree[idx].lazy = 0;
    }

    void add_lazily(int idx, int start, int end, int left, int right,
                    long long val) {
        if (right <= start || end <= left) return;
        if (start <= left && right <= end) {
            tree[idx].lazy += val;
            return;
        }

        int width = std::min(end, right) - std::max(start, left);
        tree[idx].sum += val * width;

        int mid = (left + right) / 2;
        add_lazily(idx * 2 + 0, start, end, left, mid, val);
        add_lazily(idx * 2 + 1, start, end, mid, right, val);
    }

    long long get_sum(int idx, int start, int end, int left, int right) {
        update_sum(idx, right - left);

        if (right <= start || end <= left) return 0;
        if (start <= left && right <= end) return tree[idx].sum;

        int mid = (left + right) / 2;
        return get_sum(idx * 2 + 0, start, end, left, mid) +
               get_sum(idx * 2 + 1, start, end, mid, right);
    }

   public:
    segment_tree(int size) {
        for (n = 1; n < size; n <<= 1)
            ;
        tree.resize(n * 2, {0, 0});
    }

    void add(int start, int end, long long val) {
        add_lazily(1, start, end, 0, n, val);
    }

    long long get_sum(int start, int end) {
        return get_sum(1, start, end, 0, n);
    }
};

int main() {
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);
    segment_tree st(n);

    for (int i = 0; i < n; ++i) {
        long long val;
        scanf("%lld", &val);
        st.add(i, i + 1, val);
    }

    for (int i = 0; i < m + k; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int start, end;
            long long val;
            scanf("%d %d %lld", &start, &end, &val);
            st.add(start - 1, end, val);

        } else {
            int start, end;
            scanf("%d %d", &start, &end);
            printf("%lld\n", st.get_sum(start - 1, end));
        }
    }

    return 0;
}
