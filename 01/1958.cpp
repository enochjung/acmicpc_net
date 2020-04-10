#include <stdio.h>
#include <string.h>

int n, m, l, d[110][110][110];
char a[110], b[110], c[110];

int max(int x, int y, int z)
{
	return x>y?(x>z?x:z):(y>z?y:z);
}

int main()
{
	scanf("%s %s %s", a, b, c);
	n = (int)strlen(a);
	m = (int)strlen(b);
	l = (int)strlen(c);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			for(int k=0; k<l; k++)
			{
				if(a[i]==b[j] && b[j]==c[k])
					d[i+1][j+1][k+1] = d[i][j][k]+1;
				else
					d[i+1][j+1][k+1] = max(d[i][j+1][k+1],d[i+1][j][k+1],d[i+1][j+1][k]);
			}

	printf("%d\n", d[n][m][l]);
	return 0;
}
