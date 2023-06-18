#include <cstdio>

bool producable(int p, int diff) {
    if (p == 0) return diff == 0;
    if (diff == 0) return false;
    return diff / p > 0 && diff / p * p == diff;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int p = a - b;
    while ((p & -p) > 1) p /= 2;

    for (int i = 0; i < 5; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%c\n", producable(p, x - y) ? 'Y' : 'N');
    }

    return 0;
}
