#include <cstdio>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>

#define MAX_VAL 4000

int mean(const std::vector<int> &a) {
    int sum = std::accumulate(a.begin(), a.end(), 0);
    return round((double)sum / a.size());
}

int median(const std::vector<int> &a) { return a[a.size() / 2]; }

int mode(const std::vector<int> &a) {
    struct st {
        int cnt;
        int val;
        bool operator<(const st &hs) const {
            return cnt != hs.cnt ? cnt > hs.cnt : val < hs.val;
        }
    };

    std::vector<st> vec(MAX_VAL * 2 + 1);
    for (int i = 0; i < MAX_VAL * 2 + 1; ++i) vec[i] = {0, i - MAX_VAL};

    for (int val : a) ++vec[val + MAX_VAL].cnt;

    std::sort(vec.begin(), vec.end());

    return vec[0].cnt > vec[1].cnt ? vec[0].val : vec[1].val;
}

int range(const std::vector<int> &a) { return a.back() - a.front(); }

int main() {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    std::sort(a.begin(), a.end());

    printf("%d\n", mean(a));
    printf("%d\n", median(a));
    printf("%d\n", mode(a));
    printf("%d\n", range(a));

    return 0;
}
