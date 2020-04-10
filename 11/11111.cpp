#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define N 60
#define V 2510
#define INF 999999999

using namespace std;

const int cost[5][5] = 
{
	{10, 8, 7, 5, 1},
	{8, 6, 4, 3, 1},
	{7, 4, 3, 2, 1},
	{5, 3, 2, 2, 1},
	{1, 1, 1, 1, 0}
};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m;
char a[N][N];

int c[V][V];
int d[V][V];
int f[V][V];
vector<int> edge[V];

int ctoi(char c)
{
	return c=='F'? 4 : c-'A';
}

bool is_bound(int x, int y)
{
	return 0<=x && x<n && 0<=y && y<m;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%s", a[i]);

	for(int i=1; i<=n*m/2; ++i)
	{
		c[0][i] = 1;
		edge[0].push_back(i);
		edge[i].push_back(0);
		c[i][n*m+1] = 1;
		edge[i].push_back(n*m+1);
		edge[n*m+1].push_back(i);
	}
	for(int i=n*m/2+1; i<=n*m; ++i)
	{
		c[i][n*m+1] = 1;
		edge[i].push_back(n*m+1);
		edge[n*m+1].push_back(i);
	}

	for(int i=1; i<n*m; i+=2)
	{
		int x = i/m;
		int y = i%m;
		int idx_i = i/2+1;
		int num_i = ctoi(a[x][y]);
		for(int t=0; t<4; ++t)
		{
			int tx = x+dx[t];
			int ty = y+dy[t];
			if(is_bound(tx, ty))
			{
				int j = tx*m + ty;
				int idx_j = j/2+n*m/2+1;
				int num_j = ctoi(a[tx][ty]);
				c[idx_i][idx_j] = 1;
				d[idx_i][idx_j] = -cost[num_i][num_j];
				d[idx_j][idx_i] = cost[num_i][num_j];
				edge[idx_i].push_back(idx_j);
				edge[idx_j].push_back(idx_i);
			}
		}
	}

	int res = 0;
	while(true)
	{
		int p[V], dist[V];
		bool visited[V] = {};
		queue<int> q;

		memset(p, -1, sizeof(p));
		for(int i=0; i<n*m+2; ++i)
			dist[i] = INF;
		dist[0] = 0;
		visited[0] = true;
		q.push(0);
 
		while(!q.empty())
		{
			int now = q.front();
			q.pop();

			visited[now] = false;
			for(int to : edge[now])
				if(c[now][to]-f[now][to]>0 && dist[to]>dist[now]+d[now][to])
				{
					dist[to] = dist[now]+d[now][to];
					p[to] = now;
					if(!visited[to])
					{
						q.push(to);
						visited[to] = true;
					}
				}
		}

		if(p[n*m+1] == -1)
			break;
 
		int flow = INF;
		for(int i=n*m+1; i!=0; i=p[i])
			flow = min(flow, c[p[i]][i] - f[p[i]][i]);
 
		for(int i=n*m+1; i!=0; i=p[i])
		{
			res += flow * d[p[i]][i];
			f[p[i]][i] += flow;
			f[i][p[i]] -= flow;
		}
	}

	printf("%d", -res);
	return 0;
}
