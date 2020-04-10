#include <cstdio>
#include <algorithm>
#define N 310

using namespace std;

int n, m;
int a[N][N];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			scanf("%d", &a[i][j]);
			a[i][j] += max(a[i-1][j], a[i][j-1]);
		}

	printf("%d", a[n][m]);
	return 0;
}
