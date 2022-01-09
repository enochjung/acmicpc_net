#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define N 100

using namespace std;

struct st
{
	int a, b;
	double d;
	bool operator<(const st &hs) const
	{
		return d<hs.d;
	}
};

int n, g[N];
double x[N], y[N];
vector<st> v;

double dist(int a, int b)
{
	return sqrt((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]));
}

int group(int a)
{
	return a==g[a]? a : g[a]=group(g[a]);
}

void merge(int a, int b)
{
	int ga = group(a);
	int gb = group(b);
	
	if (ga > gb)
		g[ga] = gb;
	else
		g[gb] = ga;
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%lf %lf", x+i, y+i);

	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			v.push_back({i, j, dist(i,j)});

	sort(v.begin(), v.end());
	for (int i=0; i<n; ++i)
		g[i] = i;
	
	double res = 0;
	for (st now : v)
		if (group(now.a) != group(now.b))
		{
			merge(now.a, now.b);
			res += now.d;
		}
	
	printf("%lf\n", res);
	return 0;
}