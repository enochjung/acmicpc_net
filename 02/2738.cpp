#include <cstdio>
#define N 100

int main() {
    int n, m;
    int a[N][N];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int val;
            scanf("%d", &val);
            a[i][j] += val;
        }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}