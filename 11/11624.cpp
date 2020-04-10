#include <cstdio>
#include <set>
#define N 110

using namespace std;

int n, m, q;
char l[N][N];
set<pair<int,int>> s;

bool visited[N][N] = {};
pair<int,int> val[N][N];

int dx[]={-1, 0, 1, 0}, dy[]={0, -1, 0, 1};

void insert(int vx, int vy)
{
	s.insert({vx<0? -vx : vx, vx<0? -vy : vy});
}

void dfs(int x, int y, int vx, int vy)
{
	visited[x][y] = true;
	val[x][y] = {vx, vy};

	for(int w=0; w<4; ++w)
	{
		int tx = x+dx[w];
		int ty = y+dy[w];

		if(0<=tx && tx<n && 0<=ty && ty<m)
		{
			if(l[tx][ty] == '.')
			{
				if(!visited[tx][ty])
					dfs(tx, ty, vx, vy);
				else
					insert(val[tx][ty].first-vx, val[tx][ty].second-vy);
			}
		}
		else
		{
			tx = (tx+n)%n;
			ty = (ty+m)%m;
			if(l[tx][ty] == '.')
			{
				if(!visited[tx][ty])
					dfs(tx, ty, vx+dx[w], vy+dy[w]);
				else
					insert(val[tx][ty].first-vx-dx[w], val[tx][ty].second-vy-dy[w]);
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%s", l[i]);

	dfs(0, 0, 0, 0);

	for(auto tt : s)
	{
		printf("(%d, %d)\n", tt.first, tt.second);
	}

	for(scanf("%d",&q); q--;)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		if(s.size() == 1)
		{
			if(
		}
		else if(s.size() == 2)
		{
		}
		else
		{
		}
	}
	return 0;
}
