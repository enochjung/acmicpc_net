#include <cstdio>
#include <algorithm>

#define S 3

int main() {
    int a[S], b[S];

    scanf("%*d");
    for (int i = 0; i < S; ++i) scanf("%d %d", a + i, b + i);

    int p = std::max({0, b[1] - a[2], a[0] - b[2]});

    if (p <= std::min({a[0], b[1], b[0] - a[2] + b[1]})) {
        printf("1\n");
        printf("%d %d\n", p, a[0] - p);
        printf("%d %d\n", b[0] - a[2] + b[1] - p, b[2] - a[0] + p);
        printf("%d %d\n", a[2] - b[1] + p, b[1] - p);
    } else
        printf("0\n");

    return 0;
}
