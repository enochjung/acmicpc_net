#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define N 1010

using namespace std;

struct st
{
	int t, w;

	bool operator<(const st &hs) const
	{
		return w > hs.w;
	}
};

int n, m, d[N], p[N];
vector<st> e[N];
priority_queue<st> pq;

int f(int x)
{
	if(x == 0)
		return 1;

	if(p[x] == -1)
	{
		int sum = 0;
		for(st &to : e[x])
			if(d[x] < d[to.t])
				sum += f(to.t);
		p[x] = sum;
	}
	return p[x];
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		e[a].push_back({b, c});
		e[b].push_back({a, c});
	}
	
	memset(d, 0x7f, sizeof(d));
	memset(p, -1, sizeof(p));
	d[1] = 0;
	pq.push({1, 0});
	while(!pq.empty())
	{
		int t = pq.top().t;
		int w = pq.top().w;
		pq.pop();
		if(d[t] < w)
			continue;

		for(st &to : e[t])
			if(d[to.t] > w+to.w)
			{
				d[to.t] = w+to.w;
				pq.push({to.t, d[to.t]});
			}
	}

	printf("%d", f(1));
	return 0;
}
