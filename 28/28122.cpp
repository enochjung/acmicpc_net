#include <cstdio>
#include <algorithm>
#include <vector>
#define N 200000
#define LOG_X 60

long long a[N];

long long reversed_bit(long long x) {
    long long res = 0;
    for (int i = 0; i < LOG_X; ++i) {
        res <<= 1;
        res += x & 1;
        x >>= 1;
    }
    return res;
}

int dfs(long long lval, long long rval, int lidx, int ridx, int selectable) {
    if (selectable >= ridx - lidx) return ridx - lidx;

    long long mval = (lval + rval) >> 1;
    int midx = (std::lower_bound(a + lidx, a + ridx, mval) - a);

    int lnum = midx - lidx;
    int rnum = ridx - midx;

    int max_res = 0;
    if (lnum > 0) {
        int rselect = std::min(selectable, rnum);
        max_res = std::max(
            max_res,
            dfs(lval, mval, lidx, midx, selectable - rselect + 1) + rselect);
    }
    if (rnum > 0) {
        int lselect = std::min(selectable, lnum);
        max_res = std::max(
            max_res,
            dfs(mval, rval, midx, ridx, selectable - lselect + 1) + lselect);
    }
    return max_res;
}

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
        a[i] = reversed_bit(a[i]);
    }

    std::sort(a, a + n);
    printf("%d\n", dfs(0, 1LL << LOG_X, 0, n, 0));

    return 0;
}