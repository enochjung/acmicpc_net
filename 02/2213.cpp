#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 10010

using namespace std;

int n, a[N];
vector<int> e[N], c[N];
bool visited[N];
int d[N][2];
vector<pair<int,int>> p[N][2];
vector<int> idx;

void dfs(int x)
{
	visited[x] = true;

	for(int to : e[x])
		if(!visited[to])
		{
			c[x].push_back(to);
			dfs(to);
		}
}

int f(int x, int y)
{
	if(d[x][y] == -1)
	{
		d[x][y] = y? a[x] : 0;

		for(int to : c[x])
		{
			if(y)
			{
				d[x][y] += f(to, 0);
				p[x][y].push_back({to, 0});
			}
			else
			{
				int my = f(to,1) > f(to,0);
				d[x][y] += f(to, my);
				p[x][y].push_back({to, my});
			}
		}
	}

	return d[x][y];
}

void g(int x, int y)
{
	if(y)
		idx.push_back(x);

	for(auto &i : p[x][y])
		g(i.first, i.second);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);
	for(int i=0; i<n-1; ++i)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		--p, --q;
		e[p].push_back(q);
		e[q].push_back(p);
	}

	dfs(0);
	memset(d, -1, sizeof(d));

	int my = f(0,1) > f(0,0);
	g(0, my);
	sort(idx.begin(), idx.end());

	printf("%d\n", f(0,my));
	for(int v : idx)
		printf("%d ", v+1);
	return 0;
}
