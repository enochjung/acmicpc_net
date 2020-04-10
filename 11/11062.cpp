#include <cstdio>
#include <cstring>

int t, n, a[1010], b[1010];
int d[1010][1010][2];

int f(int s, int e, int w)
{
	if(d[s][e][w] == -1)
	{
		if(s+1 == e)
			d[s][e][w] = a[s];
		else
		{
			int l = f(s+1, e, 1-w);
			int r = f(s, e-1, 1-w);

            d[s][e][w] = b[e]-b[s]-(l<r?l:r);
		}
	}

	return d[s][e][w];
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d", a+i);
			b[i+1] = b[i]+a[i];
		}

		memset(d, -1, sizeof(d));

		printf("%d\n", f(0, n, 0));
	}
	return 0;
}
