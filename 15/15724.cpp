#include <cstdio>
#define N 1030

int n, m, k, p[N][N];
int d[N][N];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d", &p[i][j]);

	for(int i=n; i>=1; --i)
		for(int j=m; j>=1; --j)
			d[i][j] = p[i][j]+d[i+1][j]+d[i][j+1]-d[i+1][j+1];

	scanf("%d", &k);
	while(k--)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", d[x1][y1]-d[x1][y2+1]-d[x2+1][y1]+d[x2+1][y2+1]);
	}

	return 0;
}
