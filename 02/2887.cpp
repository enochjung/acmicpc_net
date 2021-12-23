#include <cstdio>
#include <algorithm>
#include <vector>
#define N 100000

using namespace std;

struct edge
{
	int a, b, d;
};

int n;
pair<int,int> x[N], y[N], z[N];
vector<edge> e;
int g[N*3-3];

int group(int x)
{
	return x==g[x]? x : g[x]=group(g[x]);
}

void merge(int a, int b)
{
	int ga = group(a);
	int gb = group(b);

	if (ga < gb)
		g[ga] = gb;
	else
		g[gb] = ga;
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		x[i] = {a, i};
		y[i] = {b, i};
		z[i] = {c, i};
	}

	sort(x, x+n);
	sort(y, y+n);
	sort(z, z+n);

	for (int i=1; i<n; ++i)
	{
		e.push_back({x[i-1].second, x[i].second, x[i].first-x[i-1].first});
		e.push_back({y[i-1].second, y[i].second, y[i].first-y[i-1].first});
		e.push_back({z[i-1].second, z[i].second, z[i].first-z[i-1].first});
	}

	n = (int)e.size();
	sort(e.begin(), e.end(), [](edge &i, edge &j) { return i.d < j.d; });
	
	for (int i=0; i<n; ++i)
		g[i] = i;
	
	long long res = 0;
	for (edge i : e)
		if (group(i.a) != group(i.b))
		{
			merge(i.a, i.b);
			res += i.d;
		}

	printf("%lld\n", res);
	return 0;
}