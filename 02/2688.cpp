#include <cstdio>

int t, n;
long long d[70][10];

int main()
{
	for(int i=0; i<10; i++)
		d[1][i] = 1;
	for(int i=2; i<=64; i++)
		for(int j=0; j<10; j++)
			d[i][j] = (j>0?d[i][j-1]:0)+d[i-1][j];

	for(scanf("%d",&t); t--;)
	{
		scanf("%d", &n);
		
		long long res = 0;
		for(int i=0; i<10; i++)
			res += d[n][i];
		printf("%lld\n", res);
	}
	return 0;
}
