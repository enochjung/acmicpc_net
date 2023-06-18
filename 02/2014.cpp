#include <cstdio>
#include <queue>
#define K 100

struct option {
    int prime;
    int idx;
    long long value;
    bool operator<(const option &hs) const { return value > hs.value; }
};

struct multiplied_value {
    long long value;
    int prime;
};

int main() {
    int k, n, p[K];

    std::vector<multiplied_value> list;
    std::priority_queue<option> options;

    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; ++i) scanf("%d", p + i);

    list.push_back({1, 1});
    for (int i = 0; i < k; ++i) options.push({p[i], 0, p[i] * list[0].value});

    for (int i = 0; i < n; ++i) {
        option selected = options.top();
        options.pop();

        list.push_back({selected.value, selected.prime});

        int next_idx = selected.idx + 1;
        while (list[next_idx].prime > selected.prime) ++next_idx;

        options.push(
            {selected.prime, next_idx, list[next_idx].value * selected.prime});
    }

    printf("%lld\n", list[n].value);

    return 0;
}
