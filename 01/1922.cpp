#include <cstdio>
#include <algorithm>

using namespace std;

struct edge
{
	int s, e, c;
	bool operator<(const edge &i) const
	{
		return c < i.c;
	}
};

int n, m;
edge e[100010];
int g[10010];
long long res;

int parent(int x)
{
	return x==g[x]? x : g[x]=parent(g[x]);
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[i] = {a, b, c};
	}
	for(int i=0; i<n; i++)
		g[i] = i;

	sort(e, e+m);

	for(int i=0; i<m; i++)
	{
		int a = parent(e[i].s);
		int b = parent(e[i].e);

		if(a != b)
		{
			g[a] = b;
			res += e[i].c;
		}
	}
	
	printf("%lld\n", res);
	return 0;
}
