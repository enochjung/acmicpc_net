#include <cstdio>
#include <algorithm>
#define N 101

int n, m, a[N][N], s[N][N];

long long sum(int x1, int x2, int y1, int y2)
{
	return s[x2][y2]-s[x1][y2]-s[x2][y1]+s[x1][y1];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			scanf("%1d", &a[i][j]);

	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];

	long long res = 0;

	for (int p=1; p<m-1; ++p)
		for (int q=p+1; q<m; ++q)
			res = std::max(res, sum(0,n,0,p)*sum(0,n,p,q)*sum(0,n,q,m));
	for (int p=1; p<n-1; ++p)
		for (int q=p+1; q<n; ++q)
			res = std::max(res, sum(0,p,0,m)*sum(p,q,0,m)*sum(q,n,0,m));
	for (int p=1; p<n; ++p)
		for (int q=1; q<m; ++q)
		{
			res = std::max(res, sum(0,p,0,m)*sum(p,n,0,q)*sum(p,n,q,m));
			res = std::max(res, sum(0,n,q,m)*sum(0,p,0,q)*sum(p,n,0,q));
			res = std::max(res, sum(p,n,0,m)*sum(0,p,0,q)*sum(0,p,q,m));
			res = std::max(res, sum(0,n,0,q)*sum(0,p,q,m)*sum(p,n,q,m));
		}

	printf("%lld\n", res);
	return 0;
}