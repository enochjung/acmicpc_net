#include <cstdio>
#include <algorithm>
#define N 100001
#define M 1000000

using namespace std;

struct st
{
	int a, b, t;
	bool operator<(const st &hs) const
	{
		return t < hs.t;
	}
};

int n, m, g[N];
st a[M];

int group(int x)
{
	return x==g[x]? x : g[x]=group(g[x]);
}

void merge(int a, int b)
{
	int ga = group(a);
	int gb = group(b);

	if (ga < gb)
		g[gb] = ga;
	else
		g[ga] = gb;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i)
		scanf("%d %d %d", &a[i].a, &a[i].b, &a[i].t);
	for (int i=1; i<=n; ++i)
		g[i] = i;
	
	sort(a, a+m);

	int res = 0;
	for (int i=0,cnt=0; cnt<n-2; ++i)
		if (group(a[i].a) != group(a[i].b))
		{
			merge(a[i].a, a[i].b);
			res += a[i].t;
			++cnt;
		}

	printf("%d\n", res);
	return 0;
}