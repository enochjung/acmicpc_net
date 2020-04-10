#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int t, n, m;
int a[1010], b[1010], v[1010];
vector<int> e[1010];

bool f(int x, int lv)
{
	v[x] = lv;
	
	int size = (int)e[x].size();
	for(int i=0; i<size; i++)
	{
		int y = e[x][i];
		if(b[y]==-1 || (v[b[y]]<lv && f(b[y],lv)))
		{
			a[x] = y;
			b[y] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d", &n, &m);
		while(m--)
		{
			int p, q;
			scanf("%d %d", &p, &q);
			e[p].push_back(q);		
		}

		memset(a, -1, sizeof(a));
		memset(b, -1, sizeof(b));
		memset(v, -1, sizeof(v));

		int res = 0;
		for(int i=0; i<n; i++)
			if(a[i]==-1 && f(i,i))
				res++;
		
		printf("%d\n", res);

		for(int i=0; i<n; i++)
			e[i].clear();
	}
	return 0;
}
