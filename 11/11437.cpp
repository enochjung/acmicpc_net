#include <cstdio>
#include <vector>
#define N 50001
#define LOGN 16

using namespace std;

int n, m;
vector<int> e[N];
bool visited[N];
int depth[N], parent[N][LOGN];

void dfs(int x)
{
	visited[x] = true;

	for (int to : e[x])
		if (!visited[to])
		{
			depth[to] = depth[x]+1;
			parent[to][0] = x;
			dfs(to);
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
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}

	dfs(1);
	for (int j=1; j<LOGN; ++j)
		for (int i=1; i<=n; ++i)
			parent[i][j] = parent[parent[i][j-1]][j-1];

	scanf("%d", &m);
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}

	return 0;
}