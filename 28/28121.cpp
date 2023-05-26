#include <cstdio>
#include <vector>
#define N 300000

enum COLOR { BLACK, WHITE, GRAY };

std::vector<int> edge[N];
std::vector<int> ancestor;
std::vector<COLOR> color;
std::vector<bool> color_swapping;

COLOR swapped_color(COLOR c) {
    return c == GRAY ? GRAY : (c == BLACK ? WHITE : BLACK);
}

int get_ancestor(int x) {
    if (x != ancestor[x]) {
        int ancestor_ancestor_x = get_ancestor(ancestor[x]);
        if (ancestor[x] != ancestor_ancestor_x) {
            if (color_swapping[ancestor[x]]) {
                color[x] = swapped_color(color[x]);
                color_swapping[x] = !color_swapping[x];
            }
            ancestor[x] = ancestor_ancestor_x;
        }
    }
    return ancestor[x];
}

COLOR get_color(int x) {
    get_ancestor(x);
    return color[x];
}

void merge(int x, int y) {
    int ancestor_x = get_ancestor(x);
    int ancestor_y = get_ancestor(y);

    if (ancestor_x > ancestor_y) {
        std::swap(x, y);
        std::swap(ancestor_x, ancestor_y);
    }

    COLOR color_x = get_color(x);
    COLOR color_y = get_color(y);

    if (color_x != GRAY && color_y != GRAY && color_x == color_y) {
        color[ancestor_y] = swapped_color(color[ancestor_y]);
        color_swapping[ancestor_y] = !color_swapping[ancestor_y];
    }

    ancestor[ancestor_y] = ancestor_x;
}

int spread_gray(int x) {
    if (color[x] == GRAY) return 0;

    int ret = 1;
    color[x] = GRAY;
    for (int to : edge[x]) ret += spread_gray(to);
    return ret;
}

int connect(int x, int y) {
    edge[x].push_back(y);
    edge[y].push_back(x);

    int ancestor_x = get_ancestor(x);
    int ancestor_y = get_ancestor(y);
    COLOR color_x = get_color(x);
    COLOR color_y = get_color(y);

    if (ancestor_x != ancestor_y) merge(x, y);

    return (color[x] == GRAY || color[y] == GRAY ||
            (ancestor_x == ancestor_y && color_x == color_y))
               ? spread_gray(x) + spread_gray(y)
               : 0;
}

int main() {
    int n, q;

    scanf("%d %d", &n, &q);
    ancestor.resize(n);
    color.resize(n);
    color_swapping.resize(n);

    for (int i = 0; i < n; ++i) ancestor[i] = i;

    int good_point = 0;
    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        good_point += connect(a - 1, b - 1);
        printf("%d\n", good_point);
    }

    return 0;
}