#include <cstdio>
#include <cstring>
#include <vector>
#define N 1001

using namespace std;

int n, m;
char a[N][N];
int g[N][N];
vector<int> cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int f(int x, int y, int v)
{
	int sum = 1;
	g[x][y] = v;

	for (int w=0; w<4; ++w)
	{
		int tx = x+dx[w];
		int ty = y+dy[w];

		if (0<=tx && tx<n && 0<=ty && ty<m && a[tx][ty]=='0' && g[tx][ty]==-1)
			sum += f(tx, ty, v);
	}
	return sum;
}

int c(int x, int y)
{
	int sum = 1;
	int b[] = {-1, -1, -1, -1};

	for (int w=0; w<4; ++w)
	{
		int tx = x+dx[w];
		int ty = y+dy[w];

		if (0<=tx && tx<n && 0<=ty && ty<m && a[tx][ty]=='0')
		{
			int v = g[tx][ty];
			bool flag = true;

			for (int k=0; k<4; ++k)
				if (b[k] == v)
					flag = false;
			
			if (flag)
			{
				b[w] = v;
				sum += cnt[v];
			}
		}
	}
	return sum%10;
}

int main()
{
	memset(g, -1, sizeof(g));

	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i)
		scanf("%s", a[i]);

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (a[i][j]=='0' && g[i][j]==-1)
				cnt.push_back(f(i, j, (int)cnt.size()));

	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<m; ++j)
			printf("%d", a[i][j]=='1'? c(i,j) : 0);
		printf("\n");
	}

	return 0;
}