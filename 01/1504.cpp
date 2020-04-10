#include <cstdio>
#include <cstring>

int n, m, d[810][810], p, q;

int main()
{
	memset(d, -1, sizeof(d));

	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		d[a][b] = d[b][a] = c;
	}
	scanf("%d %d", &p, &q);

	for(int i=1; i<=n; i++)
		d[i][i] = 0;

	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(d[i][k]!=-1 && d[k][j]!=-1 && (d[i][j]==-1 || d[i][j]>d[i][k]+d[k][j]))
					d[i][j] = d[i][k]+d[k][j];

	int a = (d[1][p]!=-1 && d[p][q]!=-1 && d[q][n]!=-1)? d[1][p]+d[p][q]+d[q][n] : -1;
	int b = (d[1][q]!=-1 && d[q][p]!=-1 && d[p][n]!=-1)? d[1][q]+d[q][p]+d[p][n] : -1;

	printf("%d\n", a!=-1&&b!=-1? (a<b? a : b) : (a!=-1? a : b));
	return 0;
}
