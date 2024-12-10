#include <cstdio>
#include <algorithm>
#include <vector>
#define N 100000
#define T 200001

int n, m;
std::vector<int> children[N];
int ic_size;
int ic_start[N];
int ic_end[N];
int bit[T];

void visit(int x);
int get_value(int x);
void segment_add(int x, int val);

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int parent;
        scanf("%d", &parent);
        if (parent > 0) {
            children[parent - 1].push_back(i);
        }
    }

    ic_size = 0;
    visit(0);

    for (int i = 0; i < m; ++i) {
        int query_type;
        scanf("%d", &query_type);
        if (query_type == 1) {
            int idx, val;
            scanf("%d %d", &idx, &val);
            idx -= 1;

            segment_add(ic_end[idx], val);
            segment_add(ic_start[idx], -val);
        } else {
            int idx;
            scanf("%d", &idx);
            idx -= 1;

            int val = get_value(ic_start[idx]);
            printf("%d\n", val);
        }
    }

    return 0;
}

void visit(int x) {
    ic_start[x] = ic_size;
    ic_size += 1;

    for (int child : children[x]) {
        visit(child);
    }

    ic_end[x] = ic_size;
}

int get_value(int x) {
    int sum = 0;

    x += 1;

    while (x <= ic_size) {
        sum += bit[x];
        x += x & -x;
    }

    return sum;
}

void segment_add(int x, int val) {
    while (x > 0) {
        bit[x] += val;
        x -= x & -x;
    }
}