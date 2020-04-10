#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110

using namespace std;

int n, m, k;
bool br[N][N], bt[N][N];
long long d[N][N];

long long f(int x, int y)
{
	if(x==n && y==m)
		return 1;

	if(d[x][y] == -1)
	{
		d[x][y] = 0;
		if(x<n && !br[x][y])
			d[x][y] += f(x+1, y);
		if(y<m && !bt[x][y])
			d[x][y] += f(x, y+1);
	}
	return d[x][y];
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	while(k--)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		if(a == c)
			bt[a][min(b, d)] = true;
		else
			br[min(a, c)][b] = true;
	}

	memset(d, -1, sizeof(d));
	printf("%lld", f(0, 0));
	return 0;
}
