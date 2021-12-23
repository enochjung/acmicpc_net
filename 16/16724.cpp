#include <cstdio>
#define N 1001

int n, m;
char a[N][N];
int d[N][N];

bool f(int x, int y, int lv)
{
	d[x][y] = lv;

	int tx = x;
	int ty = y;
	if (a[x][y] == 'U')
		--tx;
	else if (a[x][y] == 'D')
		++tx;
	else if (a[x][y] == 'L')
		--ty;
	else
		++ty;

	if (d[tx][ty] == 0)
		return f(tx, ty, lv);
	else 
		return d[tx][ty] == lv;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i)
		scanf("%s", a[i]);

	int res = 0;
	int lv = 1;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (d[i][j] == 0)
				if (f(i, j, lv++))
					++res;

	printf("%d\n", res);
	return 0;
}