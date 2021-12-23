#include <cstdio>
#include <vector>
#define N 40001
#define LOGN 16

using namespace std;

struct edge
{
	int t, w;
};

int n, m;
vector<edge> two_way[N];
bool visited[N];
int depth[N], dist[N], parent[N][LOGN];

void create_tree(int x)
{
	visited[x] = true;

	for (edge &e : two_way[x])
		if (!visited[e.t])
		{
			depth[e.t] = depth[x]+1;
			dist[e.t] = dist[x]+e.w;
			parent[e.t][0] = x;
			create_tree(e.t);
		}
}

int lca(int a, int b)
{
	if (depth[a] < depth[b])
		swap(a, b);

	for (int j=0,diff=depth[a]-depth[b]; diff; ++j,diff>>=1)
		if (diff & 1)
			a = parent[a][j];

	if (a != b)
	{
		for (int j=LOGN-1; j>=0; --j)
			if (parent[a][j]!=0 && parent[a][j]!=parent[b][j])
			{
				a = parent[a][j];
				b = parent[b][j];
			}
		a = parent[a][0];
	}

	return a;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; ++i)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		two_way[a].push_back({b, w});
		two_way[b].push_back({a, w});
	}

	depth[1] = dist[1] = parent[1][0] = 0;
	create_tree(1);

	for (int j=0; j<LOGN-1; ++j)
		for (int i=1; i<=n; ++i)
			parent[i][j+1] = parent[parent[i][j]][j];

	scanf("%d", &m);
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dist[a]+dist[b]-dist[lca(a,b)]*2);
	}
	return 0;
}