#include <cstdio>

int n;
long long sum;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		sum += v;
	}
	printf("%lld", sum-(1LL*n*(n-1)/2));
	return 0;
}
