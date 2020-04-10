#include <cstdio>

int t, k, n;
long long d[30][220];

int main()
{
	d[0][0] = 1;
	for(int i=0; i<20; i++)
		for(int j=0; j<=i*(i+1)/2; j++)
			for(int k=0; k<i+2; k++)
				d[i+1][j+k] += d[i][j];

	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d", &k, &n);
		printf("%lld\n", d[k][n]);
	}
	return 0;
}
