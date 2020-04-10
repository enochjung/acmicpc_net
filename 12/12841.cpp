#include <cstdio>
#define N 100010

int n, c[N], r[2][N], p;
long long d[2][N];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", c+i);
	for(int w=0; w<2; ++w)
		for(int i=0; i<n-1; ++i)
			scanf("%d", &r[w][i]);

	for(int i=1; i<n; ++i)
		d[0][i] = d[0][i-1]+r[0][i-1];
	for(int i=0; i<n; ++i)
	{
		if(i==0 || d[0][i]+c[i]<d[1][i-1]+r[1][i-1])
		{
			d[1][i] = d[0][i]+c[i];
			p = i;
		}
		else
			d[1][i] = d[1][i-1]+r[1][i-1];
	}
	printf("%d %lld", p+1, d[1][n-1]);
	return 0;
}
