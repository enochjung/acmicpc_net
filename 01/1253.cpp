#include <cstdio>
#include <algorithm>
#define N 2000

bool is_good(int idx, int n, int a[]) {
    for (int i = 0; i < n; ++i) {
        if (i == idx) continue;

        int lidx = std::lower_bound(a + i + 1, a + n, a[idx] - a[i]) - a;
        int ridx = std::upper_bound(a + i + 1, a + n, a[idx] - a[i]) - a;

        int len = (lidx <= idx && idx < ridx ? -1 : 0) + ridx - lidx;
        if (len > 0) return true;
    }
    return false;
}

int main() {
    int n, a[N];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);

    std::sort(a, a + n);

    int res = 0;
    for (int i = 0; i < n; ++i)
        if (is_good(i, n, a)) ++res;
    printf("%d\n", res);

    return 0;
}
