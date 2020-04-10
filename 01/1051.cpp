#include <cstdio>
#define N 110

int n, m;
char a[N][N];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%s", a[i]);

	int res = 1;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			for(int k=res+1; k<=50; ++k)
				if(a[i][j]==a[i+k-1][j] && a[i][j]==a[i][j+k-1] && a[i][j]==a[i+k-1][j+k-1])
					res = k;

	printf("%d", res*res);
	return 0;
}
