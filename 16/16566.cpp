#include <cstdio>
#include <algorithm>
#define N 4000001

using namespace std;

int m, k;
int a[N], g[N];

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
	scanf("%*d %d %d", &m, &k);
	for (int i=0; i<m; ++i)
		scanf("%d", a+i);

	a[m++] = N;
	sort(a, a+m);
	for (int i=0; i<m; ++i)
		g[i] = i;

	while (k--)
	{
		int val;
		scanf("%d", &val);

		int idx = (int)(upper_bound(a, a+m, val) - a);
		int gv = group(idx);
		printf("%d\n", a[gv]);
		merge(gv, gv+1);
	}

	return 0;
}