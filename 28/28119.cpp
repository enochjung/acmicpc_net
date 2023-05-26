#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#define N 2000

struct edge {
    int a, b, cost;
    bool operator<(const edge &hs) const { return cost < hs.cost; }
};

int get_mst_cost(int n, const std::vector<edge> &e) {
    std::vector<edge> ee(e);
    std::vector<int> ancestor(n);

    std::sort(ee.begin(), ee.end());
    for (int i = 0; i < n; ++i) ancestor[i] = i;

    std::function<int(int x)> get_ancestor = [&get_ancestor, &ancestor](int x) {
        if (x != ancestor[x]) x = get_ancestor(ancestor[x]);
        return ancestor[x];
    };

    std::function<void(int a, int b)> merge = [&get_ancestor, &ancestor](
                                                  int a, int b) {
        int ancestor_a = get_ancestor(a);
        int ancestor_b = get_ancestor(b);

        if (ancestor_a > ancestor_b)
            ancestor[ancestor_a] = ancestor_b;
        else
            ancestor[ancestor_b] = ancestor_a;
    };

    int cost = 0;
    for (edge &i : ee) {
        if (get_ancestor(i.a) != get_ancestor(i.b)) {
            cost += i.cost;
            merge(i.a, i.b);
        }
    }
    return cost;
}

int main() {
    int n, m;
    std::vector<edge> e;

    scanf("%d %d %*d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e.push_back({a - 1, b - 1, c});
    }
    for (int i = 0; i < n; ++i) scanf("%*d");

    printf("%d\n", get_mst_cost(n, e));

    return 0;
}