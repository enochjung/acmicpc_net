#include <cstdio>
#include <queue>
#define N 60

using namespace std;

struct st
{
	int x, y, t, v, w;
};

const int tx[]={-1,0,1,0}, ty[]={0,-1,0,1};
int n, m;
bool room[N][N], visited[N][N][4][3];
queue<st> q;
int cx, cy, dx, dy;

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
		{
			char c;
			scanf(" %c", &c);

			if(c == 'S')
				q.push({i, j, 0, 0, -1});
			else if(c == 'C')
			{
				static bool flag = false;
				if(!flag)
				{
					cx=i, cy=j;
					flag = true;
				}
				else
					dx=i, dy=j;
			}
			else if(c == '#')
				room[i][j] = true;
		}

	while(!q.empty())
	{
		st now = q.front();
		q.pop();

		for(int w=0; w<4; ++w)
			if(w != now.w)
			{
				int nx = now.x+tx[w];
				int ny = now.y+ty[w];

				if(0<=nx && nx<n && 0<=ny && ny<m && !room[nx][ny])
				{
					int nv = now.v;
					if(cx==nx && cy==ny)
						nv |= 1;
					else if(dx==nx && dy==ny)
						nv |= 2;

					if(nv == 3)
					{
						printf("%d", now.t+1);
						return 0;
					}
					if(!visited[nx][ny][w][nv])
					{
						visited[nx][ny][w][nv] = true;
						q.push({nx, ny, now.t+1, nv, w});
					}
				}
			}
	}

	printf("-1");
	return 0;
}
