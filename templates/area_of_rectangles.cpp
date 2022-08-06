#include <algorithm>
#include <functional>
#include <vector>

struct rectangle {
    int x1, x2, y1, y2;
};

class area_of_rectangles {
   private:
    struct query {
        int x;
        int y1, y2;
        bool type_add;
    };

    class segment_tree {
       private:
        struct node {
            int gap;
            int count;
            int value;
        };

        int n;
        int size;
        std::vector<node> tree;

        void initialize_parent_node(int idx) {
            if (idx >= size) return;

            initialize_parent_node(idx * 2);
            initialize_parent_node(idx * 2 + 1);
            tree[idx].gap = tree[idx * 2].gap + tree[idx * 2 + 1].gap;
        }

        void update(int s, int e, int a, int b, int idx, int value) {
            if (b <= s || e <= a) return;
            if (s <= a && b <= e) {
                tree[idx].count += value;
                if (idx >= size)
                    tree[idx].value = tree[idx].count >= 1 ? tree[idx].gap : 0;
                else
                    tree[idx].value =
                        tree[idx].count >= 1
                            ? tree[idx].gap
                            : tree[idx * 2].value + tree[idx * 2 + 1].value;
                return;
            }

            int mid = (a + b) / 2;
            update(s, e, a, mid, idx * 2, value);
            update(s, e, mid, b, idx * 2 + 1, value);
            tree[idx].value =
                tree[idx].count >= 1
                    ? tree[idx].gap
                    : tree[idx * 2].value + tree[idx * 2 + 1].value;
        }

       public:
        segment_tree(const std::vector<int> &ypos) {
            n = (int)ypos.size() - 1;
            for (size = 1; size < n; size <<= 1)
                ;
            tree = std::vector<node>(size * 2, {0, 0, 0});
            for (int i = 0; i < n; ++i)
                tree[size + i].gap = ypos[i + 1] - ypos[i];
            initialize_parent_node(1);
        }

        int get() { return tree[1].value; }

        void add(int s, int e) { update(s + 1, e + 1, 1, size + 1, 1, 1); }

        void remove(int s, int e) { update(s + 1, e + 1, 1, size + 1, 1, -1); }
    };

    std::vector<rectangle> rectangles;

    std::vector<int> compress_with(
        const std::function<std::pair<int, int>(const rectangle &r)> op) const {
        std::vector<int> pos;

        for (rectangle r : rectangles) {
            auto value = op(r);
            pos.push_back(value.first);
            pos.push_back(value.second);
        }
        std::sort(pos.begin(), pos.end());
        pos.erase(std::unique(pos.begin(), pos.end()), pos.end());

        return pos;
    }

    std::vector<query> get_query(const std::vector<int> &xpos,
                                 const std::vector<int> &ypos) const {
        std::vector<query> queries;

        auto get_index = [](int val, const std::vector<int> &vec) -> int {
            return (int)(std::lower_bound(vec.begin(), vec.end(), val) -
                         vec.begin());
        };

        for (rectangle r : rectangles) {
            int y1_idx = get_index(r.y1, ypos);
            int y2_idx = get_index(r.y2, ypos);
            query q1 = {get_index(r.x1, xpos), y1_idx, y2_idx, true};
            query q2 = {get_index(r.x2, xpos), y1_idx, y2_idx, false};

            queries.push_back(q1);
            queries.push_back(q2);
        }

        std::sort(queries.begin(), queries.end(),
                  [](const query &lhs, const query &rhs) -> bool {
                      return lhs.x < rhs.x;
                  });

        return queries;
    }

   public:
    void add_rectangle(const rectangle &rect) { rectangles.push_back(rect); }

    long long get_area() {
        std::vector<int> xpos = compress_with(
            [](const rectangle &r) { return std::pair(r.x1, r.x2); });
        std::vector<int> ypos = compress_with(
            [](const rectangle &r) { return std::pair(r.y1, r.y2); });
        std::vector<query> queries = get_query(xpos, ypos);

        long long area = 0;
        int x_last = xpos[queries[0].x];
        segment_tree st(ypos);

        for (query q : queries) {
            area += (long long)st.get() * (xpos[q.x] - x_last);
            x_last = xpos[q.x];
            if (q.type_add)
                st.add(q.y1, q.y2);
            else
                st.remove(q.y1, q.y2);
        }

        return area;
    }
};