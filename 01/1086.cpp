#include <cstdio>
#include <cstring>
#define MAX_N 15
#define MAX_LEN 50
#define MAX_K 100

int n, k, v[MAX_N], l[MAX_N], p[MAX_LEN + 1] = {1};
char c[MAX_N][MAX_LEN + 1];
long long d[1 << MAX_N][MAX_K];

long long f(int a, int b)
{
	if (d[a][b] != -1)
		return d[a][b];
	if (a == (1 << n) - 1)
		return b == 0;

	d[a][b] = 0;
	for (int i = 0; i < n; ++i)
		if (((1 << i) & a) == 0)
			d[a][b] += f((1 << i) | a, (v[i] + b * p[l[i]]) % k);

	return d[a][b];
};

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", c[i]);
	scanf("%d", &k);

	for (int i = 0; i < n; ++i)
	{
		v[i] = [](char *s) {
			int ret = 0;
			for (int i = 0; s[i]; ++i)
				ret = (ret * 10 + s[i] - '0') % k;
			return ret;
		}(c[i]);
		l[i] = (int)strlen(c[i]);
	}
	for (int i = 1; i <= MAX_LEN; ++i)
		p[i] = p[i - 1] * 10 % k;
	memset(d, -1, sizeof(d));

	long long p, q, g;
	p = f(0, 0);
	q = [](int x) {
		long long ret = 1;
		for (; x; --x)
			ret *= x;
		return ret;
	}(n);
	g = [](long long a, long long b) {
		while (a % b)
		{
			long long tmp = a % b;
			a = b;
			b = tmp;
		}
		return b;
	}(p, q);

	p /= g, q /= g;

	printf("%lld/%lld", p, p == 0 ? 1 : q);
	return 0;
}