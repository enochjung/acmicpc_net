#include <cstdio>
#define N 5010
#define K 5010

int n, k, a[N], c[N][N];
long long d[K][N];

void f(int i, int s, int e, int p, int q)
{
	if(s > e)
		return;

	int mid = (s+e)/2;
	int t = p;
	for(int j=p; j<=q && j<mid; ++j)
		if(d[i][mid] < d[i-1][j]+c[j][mid])
		{
			d[i][mid] = d[i-1][j]+c[j][mid];
			t = j;
		}

	f(i, s, mid-1, p, t);
	f(i, mid+1, e, t, q);
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j)
			c[i][j+1] = c[i][j]|a[j];

	for(int i=1; i<=k; ++i)
		f(i, i, n, i-1, n-1);
	printf("%lld", d[k][n]);
	return 0;
}
