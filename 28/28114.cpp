#include <cstdio>
#include <algorithm>

#define N 3
#define LEN 5

struct st {
    int p;
    int y;
    char name[LEN + 1];
};

bool compare_with_y(const st &a, const st &b) { return a.y < b.y; }

bool compare_with_p(const st &a, const st &b) { return a.p > b.p; }

int main() {
    st a[N];

    for (int i = 0; i < N; ++i) scanf("%d %d %s", &a[i].p, &a[i].y, a[i].name);

    std::sort(a, a + N, compare_with_y);
    for (int i = 0; i < N; ++i) printf("%d", a[i].y % 100);
    printf("\n");

    std::sort(a, a + N, compare_with_p);
    for (int i = 0; i < N; ++i) printf("%c", a[i].name[0]);
    printf("\n");

    return 0;
}