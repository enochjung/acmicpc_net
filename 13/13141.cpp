#include <cstdio>
#include <algorithm>
#include <vector>
#define N 210
#define INF 9999999

using namespace std;

struct edge
{
	int a, b, w;
};

int n, m;
int d[N][N];
int res[N];
vector<edge> e;

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
			d[i][j] = INF;
		d[i][i] = 0;
	}
	for(int i=0; i<m; ++i)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		--a, --b;
		d[a][b] = d[b][a] = min(d[a][b], w);
		e.push_back({a, b, w});
	}

	for(int k=0; k<n; ++k)
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				if(d[i][j] > d[i][k]+d[k][j])
					d[i][j] = d[i][k]+d[k][j];

	for(auto t : e)
		for(int i=0; i<n; ++i)
			res[i] = max(res[i], d[i][t.a]+d[i][t.b]+t.w);

	int ans = INF;
	for(int i=0; i<n; ++i)
		ans = min(ans, res[i]);
	printf("%.1lf", ans/2.0);
	return 0;
}
