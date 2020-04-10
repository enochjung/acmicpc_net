#include <cstdio>
#include <algorithm>

using std::swap;
using std::min;

int t, n, p;

int main()
{
	scanf("%d", &t);

	for(int tt=1; tt<=t; ++tt)
	{
		int g[4] = {};

		scanf("%d %d", &n, &p);
		while(n--)
		{
			int v;
			scanf("%d", &v);
			++g[v%p];
		}
		
		int res = g[0];
		switch(p)
		{
		case 2:
			res += (g[1]+1)/2;
			break;

		case 3:
			if(g[1] < g[2])
				swap(g[1], g[2]);
			res += g[2]+(g[1]-g[2]+2)/3;
			break;

		case 4:
			if(g[1] < g[3])
				swap(g[1], g[3]);
			if(g[2]&1 && g[1]-g[3]!=1)
			{
				++res;
				g[1] -= 2;
			}
			res += g[3]+g[2]/2+(g[1]-g[3]+3)/4;
			break;
		}

		printf("Case #%d: %d\n", tt, res);
	}

	return 0;
}
