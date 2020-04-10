#include <cstdio>
#include <algorithm>
#define N 1010
#define INF 1e9

using namespace std;

int n, m, a[N][N];
int d[3][N];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d", &a[i][j]);

	for(int j=2; j<=m; ++j)
		d[2][j] = -INF;

	for(int i=1; i<=n; ++i)
	{
		d[0][0] = d[1][m+1] = -INF;
		for(int j=1; j<=m; ++j)
			d[0][j] = max(d[0][j-1], d[2][j])+a[i][j];
		for(int j=m; j>=1; --j)
			d[1][j] = max(d[1][j+1], d[2][j])+a[i][j];
		for(int j=1; j<=m; ++j)
			d[2][j] = max(d[0][j], d[1][j]);
	}

	printf("%d", d[2][m]);
	return 0;
}
