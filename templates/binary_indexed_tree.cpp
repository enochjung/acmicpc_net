#include <vector>

class binary_indexed_tree {
   public:
    binary_indexed_tree(int size) { tree.resize(size + 1); }

    void add(int index, int value) {
        ++index;
        while (index < tree.size()) {
            tree[index] += value;
            index += (index & -index);
        }
    }

    int sum(int start, int end) { return sum(end - 1) - sum(start - 1); }

   private:
    std::vector<int> tree;

    int sum(int index) {
        int ret = 0;
        ++index;
        while (index > 0) {
            ret += tree[index];
            index -= (index & -index);
        }
        return ret;
    }
};