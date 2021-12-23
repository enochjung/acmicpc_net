#include <cstdio>
#include <vector>
#define N 100001
#define LOGN 17

struct road
{
	int to, length;
};

int n, initial_energy[N];
std::vector<road> edge[N];
road parent[N][LOGN];

void dfs_set_parent(int x)
{
	for (road i : edge[x])
		if (parent[i.to][0].to == 0)
		{
			parent[i.to][0].to = x;
			parent[i.to][0].length = i.length;
			dfs_set_parent(i.to);
		}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		scanf("%d", initial_energy+i);
	for (int i=1; i<n; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}

	parent[1][0].to = 1;
	dfs_set_parent(1);

	for (int j=0; j<LOGN-1; ++j)
		for (int i=1; i<=n; ++i)
		{
			int my_parent = parent[i][j].to;
			parent[i][j+1].to = parent[my_parent][j].to;
			parent[i][j+1].length = parent[i][j].length + parent[my_parent][j].length;
		}

	for (int i=1; i<=n; ++i)
	{
		int position = i;
		int energy = initial_energy[i];

		for (int j=LOGN-1; j>=0; --j)
			if (energy >= parent[position][j].length)
			{
				energy -= parent[position][j].length;
				position = parent[position][j].to;
			}
		
		printf("%d\n", position);
	}

	return 0;
}