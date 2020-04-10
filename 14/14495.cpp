#include <cstdio>

int n;
long long d[120] = {0, 1, 1};

int main()
{
	scanf("%d", &n);

	for(int i=3; i<=n; ++i)
		d[i] = d[i-1]+d[i-3];

	printf("%lld", d[n]);
	return 0;
}
