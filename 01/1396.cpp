#include <cstdio>
#include <algorithm>
#include <vector>
#define N 100010

using namespace std;

struct st
{
	int a, b, c;
	bool operator<(const st &i) const
	{
		return c < i.c;
	}
};

int n, m, q, x[N], y[N], g[N], h[N];
vector<st> e;
int lo[N], hi[N];
vector<int> mid[N];
pair<int,int> res[N];

int group(int x)
{
	return g[x]==x? x : g[x]=group(g[x]);
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e.push_back({a, b, c});
	}
	scanf("%d", &q);
	for(int i=0; i<q; ++i)
		scanf("%d %d", x+i, y+i);

	sort(e.begin(), e.end());

	for(int i=0; i<q; ++i)
	{
		lo[i] = 0;
		hi[i] = m-1;
		res[i] = {-1, 0};
	}

	while(1)
	{
		bool flag = false;
		for(int i=0; i<q; ++i)
			if(lo[i] <= hi[i])
			{
				mid[(lo[i]+hi[i])/2].push_back(i);
				flag = true;
			}
		if(!flag)
			break;

		for(int i=1; i<=n; ++i)
		{
			g[i] = i;
			h[i] = 1;
		}
		for(int i=0; i<m; ++i)
		{
			int p = group(e[i].a);
			int q = group(e[i].b);
			if(p != q)
			{
				g[p] = q;
				h[q] += h[p];
			}

			for(int now : mid[i])
			{
				if(group(x[now]) == group(y[now]))
				{
					res[now] = {e[i].c, h[group(x[now])]};
					hi[now] = i-1;
				}
				else
					lo[now] = i+1;
			}
			mid[i].clear();
		}
	}

	for(int i=0; i<q; ++i)
	{
		if(res[i].first == -1)
			printf("-1\n");
		else
			printf("%d %d\n", res[i].first, res[i].second);
	}

	return 0;
}
