#include <cstdio>

int n;
long long sum, sqr;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		sum += v;
		sqr += v*v;
	}

	printf("%lld", (sum*sum-sqr)/2);
	return 0;
}