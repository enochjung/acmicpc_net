#include <cstdio>
#include <cstring>
#include <numeric>
#include <vector>
#define N 80

int d[N];

std::vector<int> str2vec(int n, char str[]) {
	std::vector<int> ret;

	int i = 0;
	while (i < n) {
		int cnt_long = 0;
		while (strncmp(str+i, "long", 4) == 0) {
			++cnt_long;
			i += 4;
		}
		if (cnt_long > 0)
			ret.push_back(cnt_long);
		++i;
	}

	return ret;
}

int f(int x) {
	if (x <= 1)
		return 1;
	if (d[x] == -1) {
		d[x] = f(x-1) + f(x-2);
	}
	return d[x];
}

int main() {
	int n;
	char str[N+1];

	memset(d, -1, sizeof(d));

	scanf("%d %s", &n, str);

	std::vector<int> vec = str2vec(n, str);
	int res = std::accumulate(vec.begin(), vec.end(), 1, [](int acc, int x) { return acc * f(x); });
	printf("%d\n", res);

    return 0;
}