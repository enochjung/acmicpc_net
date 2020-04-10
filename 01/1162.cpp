#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct edge
{
	int i, k;
	long long w;
	bool operator<(const edge &a) const
	{
		return w!=a.w? w>a.w : k<a.k;
	}
};
struct vertex
{
	int t;
	long long w;
};

int n, m, k;
bool visited[10010][30];
vector<vertex> v[10010];
priority_queue<edge> q;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	while(m--)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		a--, b--;
		v[a].push_back({b, w});
		v[b].push_back({a, w});
	}

	q.push({0, k, 0});
	while(!q.empty())
	{
		edge now = q.top();
		q.pop();

		if(now.i == n-1)
		{
			printf("%lld\n", now.w);
			return 0;
		}

		if(!visited[now.i][now.k])
		{
			visited[now.i][now.k] = true;

			int size = v[now.i].size();
			for(int i=0; i<size; i++)
			{
				int to = v[now.i][i].t;
				int weight = v[now.i][i].w;
				if(now.k>0 && !visited[to][now.k-1])
					q.push({to, now.k-1, now.w});
				if(!visited[to][now.k])
					q.push({to, now.k, now.w+weight});
			}
		}
	}
	return 0;
}
