#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int t, n, a[2][100010];
int d[2][100010];

int main()
{
	for(scanf("%d",&t); t--;)
	{
		memset(d, 0, sizeof(d));

		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", &a[0][i]);
		for(int i=0; i<n; i++)
			scanf("%d", &a[1][i]);

		for(int j=0; j<n; j++)
			for(int i=0; i<2; i++)
				d[i][j+2] = max(d[1-i][j],d[1-i][j+1])+a[i][j];

		printf("%d\n", max(d[0][n+1],d[1][n+1]));
	}
	return 0;
}
