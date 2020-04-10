#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int t, n, a;
long long l[110][110], d[110][110][2];

long long f(int p, int q, int w)
{
	if(a<p || q<a)
		return 99999999999999;

	if(d[p][q][w] == -1)
	{
		if(w)
			d[p][q][w] = min(f(p,q-1,0)+l[p][q]*(n-q+p), f(p,q-1,1)+l[q-1][q]*(n-q+p));
		else
			d[p][q][w] = min(f(p+1,q,0)+l[p][p+1]*(n-q+p), f(p+1,q,1)+l[p][q]*(n-q+p));
	}

	return d[p][q][w];
}

int main()
{
	for(scanf("%d", &t); t--;)
	{
		int r[110];
		memset(d, -1, sizeof(d));

		scanf("%d %d", &n, &a);
		for(int i=1; i<n; i++)
			scanf("%d", r+i);
		for(int i=1; i<n; i++)
		{
			int sum = 0;
			for(int j=i+1; j<=n; j++)
			{
				sum += r[j-1];
				l[i][j] = sum;
			}
		}

		d[a][a][0] = d[a][a][1] = 0;
		printf("%lld\n", min(f(1,n,0), f(1,n,1)));
	}
	
	return 0;
}
