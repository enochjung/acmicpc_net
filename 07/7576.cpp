#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct st
{
	int x, y;
};

int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};
int n, m, a[1010][1010], d[1010][1010], cnt;
int res;
queue<st> q;

int main()
{
	memset(d, -1, sizeof(d));

	scanf("%d %d", &m, &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j] == 0)
				cnt++;
			else if(a[i][j] == 1)
			{
				q.push({i, j});
				d[i][j] = 0;
			}
		}

	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for(int k=0; k<4; k++)
		{
			int nx = x+dx[k];
			int ny = y+dy[k];

			if(0<=nx && nx<n && 0<=ny && ny<m && a[nx][ny]==0 && d[nx][ny]==-1)
			{
				d[nx][ny] = d[x][y]+1;
				q.push({nx, ny});
			}
		}
	}

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(a[i][j] == 0)
			{
				if(d[i][j] == -1)
				{
					printf("-1\n");
					return 0;
				}
				res = max(res, d[i][j]);
			}

	printf("%d\n", res);
	return 0;
}
