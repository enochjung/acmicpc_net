#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 1000

using namespace std;

struct st
{
	int b, x, y, t;
};

int n, m, a[N][N];
bool v[2][N][N];
queue<st> q;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			scanf("%1d", &a[i][j]);

	v[0][0][0] = true;
	q.push({0, 0, 0, 1});
	while (!q.empty())
	{
		st now = q.front();
		q.pop();

		if (now.x==n-1 && now.y==m-1)
		{
			printf("%d\n", now.t);
			return 0;
		}

		for (int w=0; w<4; ++w)
		{
			int tx = now.x+dx[w];
			int ty = now.y+dy[w];

			if (0<=tx && tx<n && 0<=ty && ty<m)
			{
				if (a[tx][ty]==0 && !v[now.b][tx][ty])
				{
					v[now.b][tx][ty] = true;
					q.push({now.b, tx, ty, now.t+1});
				}
				else if (a[tx][ty]==1 && !now.b && !v[1][tx][ty])
				{
					v[1][tx][ty] = true;
					q.push({1, tx, ty, now.t+1});
				}
			}
		}
	}

	printf("-1\n");
	return 0;
}