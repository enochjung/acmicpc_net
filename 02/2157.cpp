#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 310

using std::max;

int n, m, k;
int d[N][N], v[N][N];

int main()
{
	memset(d, -1, sizeof(d));
	memset(v, -1, sizeof(v));

	scanf("%d %d %d", &n, &m, &k);
	while(k--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(--a < --b)
			v[a][b] = max(v[a][b], c);
	}

	d[0][1] = d[n-1][m] = 0;
	for(int i=0; i<n; ++i)
		for(int j=1; j<m; ++j)
			if(d[i][j] != -1)
			{
				for(int k=i+1; k<n; ++k)
					if(v[i][k] != -1)
						d[k][j+1] = max(d[k][j+1], d[i][j]+v[i][k]);
				d[i][j+1] = max(d[i][j+1], d[i][j]);
			}

	printf("%d", d[n-1][m]);
	return 0;
}
