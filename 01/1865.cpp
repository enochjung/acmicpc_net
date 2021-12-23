#include <cstdio>
#include <cstring>
#include <vector>
#define N 501

using namespace std;

int tc, n, m, w;
vector<pair<int,int>> e[N];

bool f()
{
	bool flag;
	vector<int> d(n+1, 0);
	
	for (int t=0; t<n; ++t)
	{
		flag = false;
		
		for (int i=1; i<=n; ++i)
			for (auto it : e[i])
			{
				int to = it.first;
				int cost = it.second;

				if (d[to] > d[i]+cost)
				{
					d[to] = d[i]+cost;
					flag = true;
				}
			}
		if (!flag)
			break;
	}
	return flag;
}

int main()
{
	for(scanf("%d",&tc); tc--;)
	{
		scanf("%d %d %d", &n, &m, &w);
		for (int i=0; i<m; ++i)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			e[a].push_back({b, c});
			e[b].push_back({a, c});
		}
		for (int i=0; i<w; ++i)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			e[a].push_back({b, -c});
		}

		printf("%s\n", f()? "YES" : "NO");
		for (int i=1; i<=n; ++i)
			e[i].clear();
	}
	
	return 0;
}