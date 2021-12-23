#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 1001
#define INF 1999999999

using namespace std;

int x, n, m, t;
vector<int> e[N];
int time[N], cost[N];
int d[N][N];

int f(int last, int now)
{
	if (last < time[1])
		return INF;
	if (last==time[1] && now==1)
		return cost[1];

	if (d[last][now] == -1)
	{
		d[last][now] = min(f(last-time[now],now)+cost[now], INF);
		for (int to : e[now])
			d[last][now] = min(d[last][now], f(last-time[now]-t,to)+cost[now]);
	}
	return d[last][now];
}

int main()
{
	memset(d, -1, sizeof(d));

	scanf("%d %d %d %d", &x, &n, &m, &t);
	for (int i=0; i<m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (int i=1; i<=n; ++i)
		scanf("%d %d", time+i, cost+i);

	int res = f(x, 1);
	if (res == INF)
		printf("It is a trap.");
	else
		printf("%d\n", res);
	return 0;
}