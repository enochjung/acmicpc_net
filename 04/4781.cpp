#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;

int n, m;
int d[10010];

int main()
{
	while(true)
	{
		int a, b;

		scanf("%d %d.%d", &n, &a, &b);
		if(n == 0) break;
		m = a*100+b;
		memset(d, -1, sizeof(d));
		d[0] = 0;

		int res = 0;
		while(n--)
		{
			int c, p;

			scanf("%d %d.%d", &c, &a, &b);
			p = a*100+b;

			for(int i=0; i+p<=m; i++)
				if(d[i]!=-1 && d[i+p]<d[i]+c)
				{
					d[i+p] = d[i]+c;
					res = max(res, d[i+p]);
				}
		}
		printf("%d\n", res);
	}

	return 0;
}
