#include <cstdio>
#include <queue>

using namespace std;

struct st
{
	int x, y, v;
	bool operator<(const st &i) const
	{
		return v < i.v;
	}
};

const int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};
int m, n, a[510][510];
int d[510][510];
bool v[510][510];
priority_queue<st> q;

int main()
{
	scanf("%d %d", &m, &n);
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &a[i][j]);

	d[0][0] = 1;
	q.push({0, 0, a[0][0]});
	v[0][0] = true;

	while(!q.empty())
	{
		int x = q.top().x;
		int y = q.top().y;
		q.pop();

		if(x==m-1 && y==n-1)
			break;

		for(int k=0; k<4; k++)
		{
			int nx = x+dx[k];
			int ny = y+dy[k];

			if(0<=nx && nx<m && 0<=ny && ny<n && a[x][y]>a[nx][ny])
			{
				d[nx][ny] += d[x][y];
				if(!v[nx][ny])
				{
					v[nx][ny] = true;
					q.push({nx, ny, a[nx][ny]});
				}
			}
		}
	}

	printf("%d\n", d[m-1][n-1]);
	return 0;
}
