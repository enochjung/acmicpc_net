#include <vector>

class bipartite_matching {
   private:
    int n, m;
    std::vector<std::vector<int>> edge;
    std::vector<int> visited, matched;

    bool dfs(int x, int lv) {
        visited[x] = lv;
        for (int target : edge[x]) {
            if (matched[target] == -1 ||
                (visited[matched[target]] < lv && dfs(matched[target], lv))) {
                matched[target] = x;
                return true;
            }
        }
        return false;
    }

   public:
    bipartite_matching(int n, int m) : n(n), m(m) {
        edge.resize(n);
        visited.resize(n, -1);
        matched.resize(m, -1);
    }

    void add_edge(int a, int b) { edge[a].push_back(b); }

    int match() {
        int count = 0;
        for (int i = 0; i < n; ++i)
            if (dfs(i, i)) ++count;
        return count;
    }
};