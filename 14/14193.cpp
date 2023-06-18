#include <cstdio>
#include <vector>

class village {
   private:
    int n, m;
    std::vector<std::vector<int>> edge;

   public:
    village(int n) : n(n) { edge.resize(n, std::vector<int>()); }

    void add_edge(int from, int to) { edge[from].push_back(to); }
};

bool can_be_conquered(const village &v) {
    // TODO
    return true;
}

int main() {
    while (true) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        village v(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            --x, --y;
            v.add_edge(x, y);
        }

        printf("%c\n", can_be_conquered(v) ? 'Y' : 'N');
    }

    return 0;
}