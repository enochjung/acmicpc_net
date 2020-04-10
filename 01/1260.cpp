#include <cstdio>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

int n, m, v;
bool visited[1010];
set<int> e[1010];

void dfs(int x)
{
	visited[x] = true;
	printf("%d ", x);
	for(auto it=e[x].begin(); it!=e[x].end(); ++it)
		if(!visited[*it])
			dfs(*it);
}

void bfs(int x)
{
	queue<int> q;

	visited[x] = true;
	q.push(x);

	while(!q.empty())
	{
		x = q.front();
		q.pop();
		printf("%d ", x);
		for(auto it=e[x].begin(); it!=e[x].end(); ++it)
			if(!visited[*it])
			{
				visited[*it] = true;
				q.push(*it);
			}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &v);
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].insert(b);
		e[b].insert(a);
	}

	dfs(v);
	memset(visited, 0, sizeof(visited));
	printf("\n");
	bfs(v);

	return 0;
}
