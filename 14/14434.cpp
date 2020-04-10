#include <cstdio>
#include <algorithm>
#include <vector>
#define N 200010

using namespace std;

int n, m, k, q, h[N], s[N];
vector<int> g[N];

int f(int t, int a, int b)
{
	int ia = (int)(upper_bound(g[a].begin(),g[a].end(),t) - g[a].begin());
	int ib = (int)(upper_bound(g[b].begin(),g[b].end(),t) - g[b].begin());
	return ia+ib;
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for(int i=0; i<m; ++i)
		scanf("%d", h+i);
	for(int i=0; i<k; ++i)
	{
		int v;
		scanf("%d", &v);
		g[v-1].push_back(i);
	}

	while(q--)
	{
		int a, b, c;
		int lo=0, hi=k, res=k;

		scanf("%d %d %d", &a, &b, &c);
		--a, --b, --c;

		while(lo <= hi)
		{
			int mid = (lo+hi)/2;
			if(f(mid, a, b) >= h[c])
			{
				res = mid;
				hi = mid-1;
			}
			else
				lo = mid+1;
		}
		++s[res];
	}

	for(int i=0; i<k; ++i)
	{
		printf("%d\n", s[i]);
		s[i+1] += s[i];
	}
	return 0;
}
