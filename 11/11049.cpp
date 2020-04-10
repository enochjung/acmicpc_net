#include <stdio.h>

int n, a[510];
long long d[510][510];

long long min(long long x, long long y)
{
	return x<y?x:y;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %d", a+i, a+i+1);
	n++;

	for(int l=2; l<n; l++)
		for(int s=0,e=l; e<n; s++,e++)
		{
			d[s][e] = 9999999999;
			for(int i=s+1; i<e; i++)
				d[s][e] = min(d[s][e], d[s][i]+d[i][e]+a[s]*a[i]*a[e]);
		}

	printf("%lld\n", d[0][n-1]);
	return 0;
}
