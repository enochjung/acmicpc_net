#include <cstdio>
#include <functional>
#include <vector>
#define N 40

int get_n_of_group(int n, std::vector<int> edge[]) {
    std::vector<bool> visited(n, false);

    int n_of_group = 0;

    std::function<void(int)> visit = [&visit, &visited, &edge](int x) {
        visited[x] = true;
        for (int to : edge[x]) {
            if (!visited[to]) {
                visit(to);
            }
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            visit(i);
            ++n_of_group;
        }
    }

    return n_of_group;
}

int main() {
    int n, m;
    std::vector<int> edge[N + 1];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    printf("%d\n", get_n_of_group(n, edge) - 1);

    return 0;
}