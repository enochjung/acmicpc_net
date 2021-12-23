#include <cstdio>
#include <algorithm>
#include <vector>
#define N 100001
#define LOGN 17

struct edge
{
	int to, w;
};

struct value
{
	int p, min, max;
};

int n, k;
std::vector<edge> e[N];
value parent[N][LOGN];
int depth[N];

void dfs(int x)
{
	for (edge &to : e[x])
		if (depth[to.to] == 0)
		{
			depth[to.to] = depth[x]+1;
			parent[to.to][0].p = x;
			parent[to.to][0].min = to.w;
			parent[to.to][0].max = to.w;
			dfs(to.to);
		}
}

void update(value &a, value b)
{
	if (a.p == -1)
		a = b;
	else
	{
		a.min = std::min(a.min, b.min);
		a.max = std::max(a.max, b.max);
	}
}

value lca(int a, int b)
{
	value ret = {-1, 0, 0};

	if (depth[a] < depth[b])
		std::swap(a, b);
	
	for (int j=0,d=depth[a]-depth[b]; d; ++j,d>>=1)
		if (d & 1)
		{
			update(ret, parent[a][j]);
			a = parent[a][j].p;
		}

	if (a != b)
	{
		for (int j=LOGN-1; j>=0; --j)
		{
			if (parent[a][j].p!=0 && parent[a][j].p!=parent[b][j].p)
			{
				update(ret, parent[a][j]);
				update(ret, parent[b][j]);
				a = parent[a][j].p;
				b = parent[b][j].p;
			}
		}
		update(ret, parent[a][0]);
		update(ret, parent[b][0]);
	}
	return ret;
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<n; ++i)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		e[a].push_back({b, w});
		e[b].push_back({a, w});
	}

	depth[1] = 1;
	dfs(1);
	
	for (int j=0; j<LOGN-1; ++j)
		for (int i=1; i<=n; ++i)
			if (parent[i][j].p != 0)
			{
				value &t = parent[i][j];
				value &tt = parent[t.p][j];
				parent[i][j+1].p = tt.p;
				parent[i][j+1].min = std::min(t.min, tt.min);
				parent[i][j+1].max = std::max(t.max, tt.max);
			}

	scanf("%d", &k);
	while (k--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		value res = lca(a, b);
		printf("%d %d\n", res.min, res.max);
	}
	return 0;
}
