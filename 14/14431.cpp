#include <cstdio>
#include <cstring>
#include <cmath>
#include <functional>
#include <queue>
#include <vector>
#define N 4010

using namespace std;

int n, x[N], y[N];
vector<pair<int,unsigned>> e[N];

void make_edge()
{
	bool np[9010] = {};

	for(int i=2; i<9000; ++i)
		if(!np[i])
			for(int j=i*i; j<9000; j+=i)
				np[j] = true;

	for(int i=0; i<n; ++i)
		for(int j=i+1; j<n; ++j)
		{
			unsigned dist = (unsigned)(sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))+1e-8);
			if(!np[dist])
			{
				e[i].push_back({j, dist});
				e[j].push_back({i, dist});
			}
		}
}

int dijkstra(int start, int end)
{
	struct st
	{
		int p;
		unsigned t;
		bool operator<(const st &i)const { return t>i.t; }
	};

	priority_queue<st> q;
	unsigned d[N];

	memset(d, -1, sizeof(d));

	q.push({start, 0});
	d[start] = 0;
	while(!q.empty())
	{
		st now = q.top();
		q.pop();

		if(d[now.p] < now.t) continue;
		if(now.p == end) return now.t;
		
		for(auto i : e[now.p])
		{
			int nx = i.first;
			unsigned nt = now.t+i.second;
			if(d[nx] > nt)
			{
				q.push({nx, nt});
				d[nx] = nt;
			}
		}
	}

	return -1;
}

int main()
{
	scanf("%d %d %d %d %d", x, y, x+1, y+1, &n);
	n += 2;
	for(int i=2; i<n; ++i)
		scanf("%d %d", x+i, y+i);

	make_edge();
	printf("%d", dijkstra(0, 1));
	return 0;
}

