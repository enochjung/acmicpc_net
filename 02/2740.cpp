#include <cstdio>
#define N 110

int n, m, k;
int a[N][N], b[N][N], c[N][N];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			scanf("%d", &a[i][j]);
	scanf("%*d %d", &k);
	for(int i=0; i<m; ++i)
		for(int j=0; j<k; ++j)
			scanf("%d", &b[i][j]); 

	for(int i=0; i<n; ++i)
		for(int j=0; j<k; ++j)
			for(int w=0; w<m; ++w)
				c[i][j] += a[i][w]*b[w][j];

	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<k; ++j)
			printf("%d ", c[i][j]);
		printf("\n");
	}
	return 0;
}
