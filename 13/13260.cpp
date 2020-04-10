#include <cstdio>
#include <algorithm>
#define M 1010

using namespace std;

int n, m, a[M], p[M][M];
long long d[M][M];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
		scanf("%d", a+i);

	a[++m-1] = n;
	sort(a, a+m+1);

	for(int i=0; i<m; ++i)
		p[i][i+1] = i;

	for(int l=2; l<=m; ++l)
		for(int i=0; i<=m-l; ++i)
		{
			int j = i+l;

			d[i][j] = 1LL<<62;
			for(int k=p[i][j-1]; k<=p[i+1][j]; ++k)
				if(d[i][j] > d[i][k]+d[k][j]+a[j]-a[i])
				{
					d[i][j] = d[i][k]+d[k][j]+a[j]-a[i];
					p[i][j] = k;
				}
		}

	printf("%lld", d[0][m]);
	return 0;
}
