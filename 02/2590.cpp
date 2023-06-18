#include <cstdio>
#include <algorithm>

#define N 6

int p[N + 1];

void remove1(int n) { p[1] = std::max(p[1] - n, 0); };

void remove2(int n) {
    int used_n = std::min(n, p[2]);
    p[2] -= used_n;
    remove1((n - used_n) * 4);
}

int use6() { return p[6]; }

int use5() {
    remove1(p[5] * 11);
    return p[5];
}

int use4() {
    remove2(p[4] * 5);
    return p[4];
}

int use3() {
    int r = p[3] % 4;
    int usable2 = r > 0 ? (3 - r) * 2 + 1 : 0;
    int usable1 = r > 0 ? 8 - r : 0;
    remove2(usable2);
    remove1(usable1);
    return (p[3] + 3) / 4;
}

int use2() {
    int r = p[2] % 9;
    int usable1 = r > 0 ? 36 - r * 4 : 0;
    remove1(usable1);
    return (p[2] + 8) / 9;
}

int use1() { return (p[1] + 35) / 36; }

int main() {
    for (int i = 1; i <= N; i++) scanf("%d", p + i);

    int res = 0;
    res += use6();
    res += use5();
    res += use4();
    res += use3();
    res += use2();
    res += use1();
    printf("%d\n", res);

    return 0;
}