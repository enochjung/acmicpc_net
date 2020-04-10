#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int t, v, e;
int g[20010];
vector<int> a[20010];

bool f(int x, int p)
{
	if(g[x] != 0)
		return p==g[x];

	g[x] = p;
	for(int to : a[x])
		if(!f(to, 3-p))
			return false;
	return true;
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d", &v, &e);
		while(e--)
		{
			int p, q;
			scanf("%d %d", &p, &q);
			a[p].push_back(q);
			a[q].push_back(p);
		}

		bool res = true;
		for(int i=1; i<=v; i++)
			if(g[i]==0 && !f(i,1))
			{
				res = false;
				break;
			}
		printf("%s\n", res?"YES":"NO");

		memset(g, 0, sizeof(g));
		for(int i=1; i<=v; i++)
			a[i].clear();
	}
	return 0;
}
