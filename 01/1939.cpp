#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define N 10010
#define INF 2111111111

using namespace std;

struct st
{
	int i, w;
	bool operator<(const st &h) const
	{
		return w<h.w;
	}
};

int n, m, s, e;
int d[N];
priority_queue<st> q;
vector<st> edge[N];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}
	scanf("%d %d", &s, &e);

	d[s] = INF;
	q.push({s, INF});

	while(!q.empty())
	{
		int i = q.top().i;
		int w = q.top().w;
		q.pop();
		if(d[i] > w)
			continue;

		for(st to : edge[i])
			if(d[to.i] < min(w,to.w))
			{
				d[to.i] = min(w,to.w);
				q.push({to.i, d[to.i]});
			}
	}

	printf("%d", d[e]);
	return 0;
}
