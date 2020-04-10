#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int n;
int q[10010], v[10010];
vector<int> e[10010];

int f(int x, int lv)
{
	v[x] = lv;

	for(int y : e[x])
		if(q[y]==-1 || (v[q[y]]<lv && f(q[y],lv)))
		{
			q[y] = x;
			return true;
		}
	return false;
}

int main()
{
	while(scanf("%d",&n) != -1)
	{
		for(int i=0; i<n; i++)
		{
			int j, s;
			scanf("%d: (%d)", &j, &s);

			e[j].clear();
			while(s--)
			{
				int a;
				scanf("%d", &a);
				e[j].push_back(a-n);
			}
		}

		int res = 0;

		memset(q, -1, sizeof(q));
		memset(v, -1, sizeof(v));
		for(int i=0; i<n; i++)
			if(f(i, i))
				res++;

		printf("%d\n", res);
	}
	return 0;
}
