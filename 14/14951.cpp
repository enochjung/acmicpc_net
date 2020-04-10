#include <cstdio>
#include <algorithm>
#include <vector>
#define N 5010

using namespace std;

int n;
int d[N];
vector<int> relationship[N], parent, children[N], child_depth;
vector<vector<int>> kinship[N], kinship_children[N];

void input()
{
	scanf("%d", &n);
	for(int i=0; i<n-1; ++i)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		--p, --q;
		relationship[p].push_back(q);
		relationship[q].push_back(p);
	}
}

void make_tree_dfs(int x, bool visited[])
{
	visited[x] = true;
	for(int to : relationship[x])
		if(!visited[to])
		{
			parent[to] = x;
			children[x].push_back(to);
			make_tree_dfs(to, visited);
		}
}

void make_tree()
{
	bool visited[N] = {};
	parent.resize(n);
	make_tree_dfs(0, visited);
}

void make_kinship_dfs(int x, int target, int depth, bool visited[])
{
	visited[x] = true;
	if(depth == (int)kinship[target].size())
		kinship[target].resize(depth+1);
	kinship[target][depth].push_back(x);
	for(int to : relationship[x])
		if(!visited[to])
			make_kinship_dfs(to, target, depth+1, visited);
}

void make_kinship()
{
	for(int i=0; i<n; ++i)
	{
		bool visited[N] = {};
		make_kinship_dfs(i, i, 0, visited);
	}
}

int make_kinship_children_dfs(int x, int target, int depth)
{
	int max_depth = depth;
	if(depth == (int)kinship_children[target].size())
		kinship_children[target].resize(depth+1);
	kinship_children[target][depth].push_back(x);
	for(int to : children[x])
	{
		int ret_depth = make_kinship_children_dfs(to, target, depth+1);
		max_depth = max(max_depth, ret_depth);
	}
	return max_depth;
}

void make_kinship_children()
{
	child_depth.resize(n);
	for(int i=0; i<n; ++i)
		child_depth[i] = make_kinship_children_dfs(i, i, 0);
}

int get_dp(int x)
{
	if(d[x] == 0)
	{
		d[x] = max(1, child_depth[x]);
		for(int radius=1; radius<=(int)kinship_children[x].size()-1; ++radius)
			for(int child : kinship_children[x][radius])
			{
				int sum = radius;
				for(int child_kinship : kinship[child][radius+1])
					if(child_kinship != parent[x])
						sum += get_dp(child_kinship);
				d[x] = min(d[x], sum);
			}
	}
	return d[x];
}

void calculate()
{
	d[0] = max(1, child_depth[0]);
	for(int radius=1; radius<=(int)kinship_children[0].size()-1; ++radius)
	{
		int sum = radius;
		if(radius+1 < (int)kinship_children[0].size())
			for(int child : kinship_children[0][radius+1])
				sum += get_dp(child);
		d[0] = min(d[0], sum);
	}

	for(int radius=1; radius<=(int)kinship_children[0].size()-1; ++radius)
		for(int child : kinship_children[0][radius])
			for(int radius_child=radius; radius_child<=(int)kinship[child].size()-1; ++radius_child)
			{
				int sum = radius_child;
				if(radius_child+1 < (int)kinship[child].size())
					for(int child_kinship : kinship[child][radius_child+1])
						sum += get_dp(child_kinship);
				d[0] = min(d[0], sum);
			}
}

int main()
{
	input();
	make_tree();
	make_kinship();
	make_kinship_children();
	calculate();
	printf("%d", d[0]);
	return 0;
}
