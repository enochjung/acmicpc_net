#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define N 1001

using namespace std;

int n, m, x;
int d1[N], d2[N];
vector<pair<int,int>> e1[N], e2[N];

void f(int *d, vector<pair<int,int>> *e)
{
	priority_queue<pair<int,int>> pq;

	memset(d, -1, sizeof(int)*N);
	pq.push({0, x});
	d[x] = 0;

	while (!pq.empty())
	{
		int t = -pq.top().first;
		int i = pq.top().second;
		pq.pop();

		if (t > d[i])
			continue;

		for (auto j : e[i])
		{
			int to = j.first;
			int tt = t+j.second;

			if (d[to]==-1 || d[to]>tt)
			{
				d[to] = tt;
				pq.push({-tt, to});
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &x);
	for (int i=0; i<m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e1[a].push_back({b, c});
		e2[b].push_back({a, c});
	}

	f(d1, e1);
	f(d2, e2);

	int res = 0;
	for (int i=1; i<=n; ++i)
		res = max(res, d1[i]+d2[i]);

	printf("%d\n", res);
	return 0;
}