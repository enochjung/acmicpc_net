#include <cstdio>
#include <algorithm>
#define INF 99999

using namespace std;

int t, n, w, a[2][10010];
int d[3][10010];

int f(int x)
{
	for(int j=0; j<=n; j++)
	{
		d[0][j] = d[1][j] = INF;

		for(int i=0; i<2; i++)
		{
			if(a[i][j] != INF)
				d[i][j] = (j>0? d[2][j-1] : 0) + (a[i][j]>0);
			if(j>0 && a[i][j]+a[i][j-1]<=w)
				d[i][j] = min(d[i][j], d[1-i][j-1]+1);
		}

		d[2][j] = min(d[0][j]+(a[1][j]>0), d[1][j]+(a[0][j]>0));

		if(a[0][j]+a[1][j] <= w)
			d[2][j] = min(d[2][j], j>0? d[2][j-1]+1 : 1);
		if(j>0 && a[0][j]+a[0][j-1]<=w && a[1][j]+a[1][j-1]<=w)
			d[2][j] = min(d[2][j], j>1? d[2][j-2]+2 : 2);
	}

	return x<3? d[2-x][n] : d[2][n-1];
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d", &n, &w);
		for(int i=0; i<2; i++)
			for(int j=1; j<=n; j++)
				scanf("%d", &a[i][j]);

		int res = INF;
		for(int i=0; i<4; i++)
		{
			if(i & 1)
				a[0][0]=a[0][n], a[0][n]=INF;
			if(i > 1)
				a[1][0]=a[1][n], a[1][n]=INF;

			res = min(res, f(i));

			if(i & 1)
				a[0][n]=a[0][0], a[0][0]=0;
			if(i > 1)
				a[1][n]=a[1][0], a[1][0]=0;
		}
		printf("%d\n", res);
	}
	return 0;
}
