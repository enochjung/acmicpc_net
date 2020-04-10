#include <cstdio>
#include <queue>
#define N 2010
#define K 100010

using namespace std;

struct st
{
	int x, y;
};

int n, k;
int a[N][N], g[K];
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
queue<st> p, q;

int group(int x)
{
	return x==g[x]? x : g[x]=group(g[x]);
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=1; i<=k; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		q.push({x, y});
		a[x][y] = i;
		g[i] = i;
	}

	int t = -1;
	for(; k>1; ++t)
	{
		while(!p.empty())
		{
			st now = p.front();
			p.pop();

			int x = now.x;
			int y = now.y;
			for(int w=0; w<4; ++w)
			{
				int tx = x+dx[w];
				int ty = y+dy[w];

				if(1<=tx && tx<=n && 1<=ty && ty<=n && !a[tx][ty])
				{
					a[tx][ty] = a[x][y];
					q.push({tx, ty});
				}
			}
		}

		while(!q.empty())
		{
			st now = q.front();
			p.push(now);
			q.pop();

			int x = now.x;
			int y = now.y;
			for(int w=0; w<4; ++w)
			{
				int tx = x+dx[w];
				int ty = y+dy[w];

				if(1<=tx && tx<=n && 1<=ty && ty<=n && a[tx][ty])
				{
					int ga = group(a[tx][ty]);
					int gb = group(a[x][y]);
					if(ga != gb)
					{
						--k;
						if(ga > gb)
							g[ga] = gb;
						else
							g[gb] = ga;
					}
				}
			}
		}
	}

	printf("%d", t);
	return 0;
}
