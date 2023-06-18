#include <cstdio>

int gcd(long long x, long long y) {
    while (x % y) {
        long long tmp = y;
        y = x % y;
        x = tmp;
    }
    return (int)y;
}

int isqrt(long long x) {
    long long m = (1LL << 60);
    long long r = 0;
    do {
        long long nr = m | r;
        r >>= 1;
        if (nr <= x) {
            x -= nr;
            r += m;
        }
        m >>= 2;
    } while (m != 0);
    return (int)r;
}

int get_n_of_squared(long long start, long long end) {
    int sq_start = isqrt(start - 1) + 1;
    int sq_end = isqrt(end - 1) + 1;
    return sq_end - sq_start;
}

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);

    int count = get_n_of_squared(a + 1, b + 1);
    long long width = b - a;

    if (count == 0)
        printf("0\n");
    else {
        int g = gcd(count, width);
        printf("%d/%lld\n", count / g, width / g);
    }

    return 0;
}
