#include <stdio.h>
#include <string.h>

char a[2][110], s[30];
int n, m, d[2][110][30];

int main()
{
	scanf("%s", s);
	scanf("%s %s", a[0], a[1]);

	n = (int)strlen(s);
	m = (int)strlen(a[0]);

	for(int i=0; i<2; i++)
		for(int j=0; j<m; j++)
			if(a[i][j] == s[0])
				d[i][j][0] = 1;

	for(int k=1; k<n; k++)
		for(int i=0; i<2; i++)
			for(int j=k; j<m; j++)
				if(a[i][j] == s[k])
					for(int t=0; t<j; t++)
						d[i][j][k] += d[1-i][t][k-1];

	int res = 0;
	for(int i=0; i<2; i++)
		for(int j=0; j<m; j++)
			res += d[i][j][n-1];
	printf("%d\n", res);
	return 0;
}
