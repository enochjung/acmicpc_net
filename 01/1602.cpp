#include <stdio.h>
#include <algorithm>
#define INF 999999999

using namespace std;

struct city
{
	int idx, cost;
	bool operator<(const city &i) const {
		return cost < i.cost;
	}
} c[510];

int n, m, q;
int r[510], l[510][510], d[510][510];

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for(int i=0; i<n; i++)
	{
		int w;
		scanf("%d", &w);
		c[i].idx = i+1;
		c[i].cost = w;
		r[i+1] = w;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			l[i][j] = i==j? 0 : INF;
			d[i][j] = i==j? r[i] : INF;
		}
	for(int i=0; i<m; i++)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		l[a][b] = l[b][a] = w;
	}

	sort(c, c+n);

	for(int t=0; t<n; t++)
	{
		int k = c[t].idx;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
			{
				l[i][j] = min(l[i][j], l[i][k]+l[k][j]);
				d[i][j] = min(d[i][j], l[i][k]+l[k][j]+max(max(r[i],r[k]),r[j]));
			}
	}

	while(q--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", d[a][b]<INF? d[a][b] : -1);
	}
	return 0;
}
