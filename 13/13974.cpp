#include <cstdio>
#define K 5010

int t, k, a[K], p[K][K];
long long s[K], d[K][K];

// s[i] = sum of a[0] ~ a[i-1]
int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d", &k);
		for(int i=0; i<k; ++i)
			scanf("%d", a+i);

		for(int i=0; i<k; ++i)
		{
			s[i+1] = s[i]+a[i];
			p[i][i+1] = i;
		}

		for(int l=2; l<=k; ++l)
			for(int i=0; i<=k-l; ++i)
			{
				int j = i+l;

				d[i][j] = 1LL<<62;
				for(int q=p[i][j-1]; q<=p[i+1][j]; ++q)
					if(d[i][j] > d[i][q]+d[q][j])
					{
						d[i][j] = d[i][q]+d[q][j];
						p[i][j] = q;
					}
				d[i][j] += s[j]-s[i];
			}
		printf("%lld\n", d[0][k]);
	}

	return 0;
}
