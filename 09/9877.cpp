#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define M 510

using namespace std;

struct st
{
	int a, b, c;
};

int m, n, t, h[M][M];
int g[M*M], c[M*M], s[M*M];
vector<st> e;

int find(int x)
{
	return g[x]==x? x : g[x]=find(g[x]);
}

inline int num(int x, int y)
{
	return x*n+y;
}

int main()
{
	scanf("%d %d %d", &m, &n, &t);
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
		{
			scanf("%d", &h[i][j]);
			if(i)
				e.push_back({num(i,j), num(i-1,j), abs(h[i][j]-h[i-1][j])});
			if(j)
				e.push_back({num(i,j), num(i,j-1), abs(h[i][j]-h[i][j-1])});
		}
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
		{
			int v;
			scanf("%d", &v);
			if(v)
				++s[num(i, j)];
		}
	if(t == 1)
	{
		printf("0");
		return 0;
	}

	sort(e.begin(), e.end(), [&](const st &i, const st &j) { return i.c < j.c; });
	for(int i=0; i<m*n; ++i)
	{
		g[i] = i;
		c[i] = 1;
	}

	long long res = 0;
	for(st now : e)
	{
		int p = find(now.a);
		int q = find(now.b);
		if(p != q)
		{
			g[p] = q;
			c[q] += c[p];
			s[q] += s[p];
		}
		if(c[q] >= t)
		{
			res += 1LL*now.c*s[q];
			s[q] = 0;
		}
	}
	printf("%lld", res);
	return 0;
}
