#include <cstdio>
#define BIG (1e15)

int n, m;
long long d[2][110][110];

int main()
{
	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++)
		d[0][i][0] = d[0][i][i] = 1;

	for(int i=2; i<=n; i++)
		for(int j=1; j<i; j++)
		{
			d[0][i][j] = d[0][i-1][j-1]+d[0][i-1][j];
			d[1][i][j] = d[1][i-1][j-1]+d[1][i-1][j];
			if(d[0][i][j] >= BIG)
			{
				d[1][i][j]++;
				d[0][i][j] -= BIG;
			}
		}

	if(d[1][n][m] != 0)
		printf("%lld%015lld\n", d[1][n][m], d[0][n][m]);
	else
		printf("%lld\n", d[0][n][m]);
	return 0;
}
