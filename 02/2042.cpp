#include <cstdio>
#include <functional>
#include <vector>

template <typename T>
class binary_tree {
   public:
    binary_tree(int n, std::function<T(T, T)> type, T initial_value)
        : type(type), initial_value(initial_value) {
        for (size = 1; size < n; size <<= 1)
            ;
        tree.resize(size * 2, initial_value);
    }

    void set(int index, T value) {
        index += size;
        tree[index] = value;
        while (index > 1) {
            int parent = index / 2;
            int child1 = parent * 2;
            int child2 = parent * 2 + 1;
            tree[parent] = type(tree[child1], tree[child2]);
            index /= 2;
        }
    }

    T get(int start, int end) { return get(start, end, 0, size, 1); }

   private:
    T initial_value;
    int size;
    std::vector<T> tree;
    std::function<T(T, T)> type;

    T get(int start, int end, int leftmost, int rightmost, int index) {
        if (start <= leftmost && rightmost <= end) return tree[index];
        if (rightmost <= start || end <= leftmost) return initial_value;

        int middle = (leftmost + rightmost) / 2;
        T left = get(start, end, leftmost, middle, index * 2);
        T right = get(start, end, middle, rightmost, index * 2 + 1);
        return type(left, right);
    }
};

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    binary_tree<long long> tree(
        n, [](long long lhs, long long rhs) { return lhs + rhs; }, 0);

    for (int i = 0; i < n; ++i) {
        long long v;
        scanf("%lld", &v);
        tree.set(i, v);
    }

    for (int i = 0; i < m + k; ++i) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1)
            tree.set(b - 1, c);
        else
            printf("%lld\n", tree.get(b - 1, c));
    }

    return 0;
}
