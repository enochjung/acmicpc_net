#include <cstdio>
#include <algorithm>
#define N 2000010

using namespace std;

int n, a[N];
long long b[N], c[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);

	for (int i = 1; i <= n; ++i)
		b[i] = b[i - 1] + a[i - 1] * a[i - 1];
	for (int i = n - 1; i >= 0; --i)
		c[i] = c[i + 1] + a[i];

	long long res = 0;
	for (int i = 1; i < n; ++i)
		res = max(res, b[i] * c[i]);

	printf("%lld\n", res);
	return 0;
}