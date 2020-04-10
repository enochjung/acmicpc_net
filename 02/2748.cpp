#include <cstdio>

int n;
long long d[100]={0,1};

int main()
{
	scanf("%d", &n);

	for(int i=2; i<=n; i++)
		d[i] = d[i-1]+d[i-2];

	printf("%lld\n", d[n]);
	return 0;
}

