#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define V 20010
#define INF 2111111111

using namespace std;

struct st
{
	int t, w;
	bool operator<(const st &i) const
	{
		return w>i.w;
	}
};

int v, e, k;
int d[V];
priority_queue<st> q;
vector<st> edge[V];

int main()
{
	scanf("%d %d %d", &v, &e, &k);
	for(int i=0; i<e; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back({b, c});
	}

	memset(d, 0x7f, sizeof(d));
	d[k] = 0;
	q.push({k, 0});

	while(!q.empty())
	{
		int t = q.top().t;
		int w = q.top().w;
		q.pop();
		if(d[t] < w)
			continue;

		for(st to : edge[t])
			if(d[to.t] > w+to.w)
			{
				d[to.t] = w+to.w;
				q.push({to.t, d[to.t]});
			}
	}

	for(int i=1; i<=v; ++i)
	{
		if(d[i] < INF)
			printf("%d\n", d[i]);
		else
			printf("INF\n"); 
	}

	return 0;
}
