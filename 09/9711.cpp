#include <cstdio>

int fibo(int x, int mod) {
    int a[3] = {0, 1 % mod, 0};

    for (int i = 2; i <= x; ++i)
        a[i % 3] = (0LL + a[(i + 2) % 3] + a[(i + 1) % 3]) % mod;

    return a[x % 3];
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; ++i) {
        int p, q;
        scanf("%d %d", &p, &q);
        printf("Case #%d: %d\n", i, fibo(p, q));
    }
    return 0;
}
