#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#define N 81

using namespace std;

int n, r, h, m;
vector<int> e[N];
bool visited[N];
int radius;
vector<int> center;
int parent[N];

void find_center()
{
	function<int(int)> dfs = [&](int x)
	{
		visited[x] = true;

		int max_len = 0;
		for (int to : e[x])
			if (!visited[to])
				max_len = max(max_len, dfs(to)+1);
		return max_len;
	};

	radius = 99;
	for (int i=1; i<=n; ++i)
	{
		memset(visited, 0, sizeof(visited));
		int len = dfs(i);
		if (radius > len)
		{
			radius = len;
			center.clear();
			center.push_back(i);
		}
		else if (radius == len)
			center.push_back(i);
	}
}

void create_tree()
{
	function<void(int)> dfs = [&](int x)
	{
		for (int to : e[x])
			if (parent[to] == 0)
			{
				parent[to] = x;
				dfs(to);
			}
	};

	parent[center.front()] = -1;
	dfs(center.front());
}

bool can_squirrel_go_to(int target)
{
	function<bool(int)> dfs = [&](int x)
	{
		visited[x] = true;
		if (x == target)
			return true;
		
		for (int to : e[x])
			if (!visited[to] && to!=h && to!=m)
				if (dfs(to))
					return true;
		return false;
	};

	memset(visited, 0, sizeof(visited));
	return dfs(r);
}

int find_raven_to_center(int x)
{
	while (x!=h && x!=m && x!=center.front())
		x = parent[x];
	return x;
}

int dist_to_center(int x)
{
	int cnt = 0;
	for (; x!=center.front(); ++cnt)
		x = parent[x];
	return cnt;
}

int main()
{
	scanf("%d %d %d %d", &n, &r, &h, &m);
	for (int i=0; i<n-1; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}

	find_center();
	create_tree();

	bool center0 = can_squirrel_go_to(center.front());
	bool center1 = can_squirrel_go_to(center.back());
	if (center0 && center1)
		printf("%d\n", radius+1);
	else if (center0 || center1)
		printf("%d\n", radius);
	else
	{
		int raven = find_raven_to_center(r);
		int dist = dist_to_center(raven);
		printf("%d\n", radius - dist);
	}

	return 0;
}