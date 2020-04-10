#include <stdio.h>

int t, n, m;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		int nx1[210], ny[210], nx2[210], nw[210];
		int mx[210], my1[210], my2[210], mw[210];

		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++)
			scanf("%d %d %d %*d %d", nx1+i, ny+i, nx2+i, nw+i);
		for(int i=0; i<m; i++)
			scanf("%d %d %*d %d %d", mx+i, my1+i, my2+i, mw+i);
	}
}
