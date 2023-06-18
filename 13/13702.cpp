#include <cstdio>
#include <vector>

long long get_capacity(const std::vector<int> &water, unsigned int x) {
    long long sum = 0;
    for (int w : water) sum += w / x;
    return sum;
}

int get_answer(const std::vector<int> &water, int k) {
    unsigned int low = 0;
    unsigned int high = (1 << 31);

    while (low + 1 < high) {
        unsigned int mid = (low + high) / 2;

        if (get_capacity(water, mid) >= k)
            low = mid;
        else
            high = mid;
    }

    return (int)low;
}

int main() {
    int n, k;
    std::vector<int> water;

    scanf("%d %d", &n, &k);
    water.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &water[i]);

    printf("%d\n", get_answer(water, k));
    return 0;
}
