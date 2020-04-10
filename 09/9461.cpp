#include <cstdio>

int t, n;
long long a[110] = {1, 1, 1, 2, 2};

int main()
{
	for(int i=5; i<100; ++i)
		a[i] = a[i-1]+a[i-5];
	for(scanf("%d",&t); t--;)
	{
		scanf("%d", &n);
		printf("%lld\n", a[n-1]);
	}
	return 0;
}
