#include <cstdio>

int t, n;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d", &n);

		long long res=n&1?-1:1, fact=1;
		for(int i=n; i>=1; --i)
		{
			fact *= i;
			res += i&1? fact : -fact;
		}
		printf("%lld\n", res);
	}
	return 0;
}
