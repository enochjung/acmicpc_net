#include <cstdio>
#include <queue>
#define N 100

struct point
{
	int x, y, z, t;
};

int h, n, m, a[N][N][N];
std::queue<point> q;
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

int main()
{
	scanf("%d %d %d", &m, &n, &h);
	for (int i=0; i<h; ++i)
		for (int j=0; j<n; ++j)
			for (int k=0; k<m; ++k)
				scanf("%d", &a[i][j][k]);

	for (int i=0; i<h; ++i)
		for (int j=0; j<n; ++j)
			for (int k=0; k<m; ++k)
				if (a[i][j][k] == 1)
					q.push({i, j, k, 0});

	int res = 0;
	while (!q.empty())
	{
		point p = q.front();
		q.pop();
		res = p.t;

		for (int w=0; w<6; ++w)
		{
			int tx = p.x+dx[w];
			int ty = p.y+dy[w];
			int tz = p.z+dz[w];

			if (0<=tx && tx<h && 0<=ty && ty<n && 0<=tz && tz<m && a[tx][ty][tz] == 0)
			{
				a[tx][ty][tz] = 1;
				q.push({tx, ty, tz, p.t+1});
			}
		}
	}

	for (int i=0; i<h; ++i)
		for (int j=0; j<n; ++j)
			for (int k=0; k<m; ++k)
				if (a[i][j][k] == 0)
				{
					printf("-1\n");
					return 0;
				}
	printf("%d\n", res);
	return 0;
}