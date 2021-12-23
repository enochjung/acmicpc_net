#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define N 500

using namespace std;

struct edge
{
	int t, c;
	bool operator<(const edge &hs) const
	{
		return c>hs.c;
	}
};

int n, m, s, e;
vector<edge> l[N], r[N];
int dist[N];
priority_queue<edge> pq;
bool visited[N];

void dijkstra()
{
	memset(dist, -1, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	dist[s] = 0;
	pq.push({s, 0});
	while (!pq.empty())
	{
		edge now = pq.top();
		pq.pop();
		if (visited[now.t])
			continue;
		visited[now.t] = true;

		for (edge &to : l[now.t])
			if (dist[to.t]==-1 || dist[to.t]>now.c+to.c)
			{
				dist[to.t] = now.c+to.c;
				pq.push({to.t, dist[to.t]});
			}
	}
}

void remove(int x)
{
	for (edge &to : r[x])
		if (to.c!=-1 && dist[to.t]+to.c==dist[x])
		{
			to.c = -1;
			remove(to.t);
		}
}

int main()
{
	while (true)
	{
		scanf("%d %d", &n, &m);
		if (n == 0)
			break;
		scanf("%d %d", &s, &e);
		while (m--)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			l[a].push_back({b, c});
			r[b].push_back({a, c});
		}

		dijkstra();
		remove(e);

		for (int i=0; i<n; ++i)
			l[i].clear();
		for (int i=0; i<n; ++i)
			for (edge &to : r[i])
				if (to.c != -1)
					l[to.t].push_back({i, to.c});
		
		dijkstra();
		
		printf("%d\n", dist[e]);

		for (int i=0; i<n; ++i)
		{
			l[i].clear();
			r[i].clear();
		}
	}

	return 0;
}