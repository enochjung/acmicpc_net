#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define N 1001
#define MAX 999999999

using namespace std;

int n, m, p, q;
vector<pair<int,int>> e[N];
int d[N];
priority_queue<pair<int,int>> pq;

int main()
{
	scanf("%d %d", &n, &m);
	while (m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[a].push_back({b, c});
	}
	scanf("%d %d", &p, &q);

	for (int i=1; i<=n; ++i)
		d[i] = MAX;
	d[p] = 0;
	pq.push({0, p});
	while(!pq.empty())
	{
		int x = pq.top().second;
		int t = -pq.top().first;
		pq.pop();
		
		if (d[x] < t)
			continue;

		for (auto to : e[x])
			if (d[to.first] > d[x]+to.second)
			{
				d[to.first] = d[x]+to.second;
				pq.push({-d[to.first], to.first});
			}
	}
	
	printf("%d\n", d[q]);
	return 0;
}