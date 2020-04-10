#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define N 50010

using namespace std;

struct st
{
	int d, t;
	bool operator<(const st &hs) const
	{
		return t>hs.t;
	}
};

int n, m, k, y[N], d[2][N];
vector<st> e[N];
priority_queue<st> pq;

void update(int p)
{
	while(!pq.empty())
	{
		int i = pq.top().d;
		int t = pq.top().t;
		pq.pop();

		if(d[p][i] < t)
			continue;

		for(st to : e[i])
			if(d[p][to.d]==-1 || d[p][to.d]>t+to.t)
			{
				d[p][to.d] = t+to.t;
				pq.push({to.d, d[p][to.d]});
			}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	while(m--)
	{
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		--a, --b;
		e[a].push_back({b, t});
		e[b].push_back({a, t});
	}
	while(k--)
	{
		int i, v;
		scanf("%d %d", &i, &v);
		--i;
		y[i] = max(y[i], v);
	}

	memset(d, 0x7f, sizeof(d));

	d[0][n-1] = 0;
	pq.push({n-1, 0});
	update(0);
	for(int i=0; i<n; ++i)
		if(y[i])
		{
			d[1][i] = d[0][i]-y[i];
			pq.push({i, d[1][i]});
		}
	update(1);

	for(int i=0; i<n-1; ++i)
		printf("%d\n", d[0][i]>=d[1][i]);
	return 0;
}