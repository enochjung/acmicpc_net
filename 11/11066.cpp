#include <stdio.h>

int t, n, a[510];

int main()
{
	for(scanf("%d",&t); t--;)
	{
		int d[510][510] = {};

		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", a+i);

		for(int i=1; i<n; i++)
			a[i] += a[i-1];

		for(int l=2; l<=n; l++)
			for(int s=0,e=l; e<=n; s++,e++)
			{
				d[s][e] = 99999999;
				for(int i=s+1; i<e; i++)
					if(d[s][e] > d[s][i]+d[i][e])
						d[s][e] = d[s][i]+d[i][e];
				d[s][e] += a[e-1]-(s>0?a[s-1]:0);
			}

		printf("%d\n", d[0][n]);
	}
	return 0;
}
