#include <stdio.h>
#include <string.h>

int n, m, k;
char a[110][110], b[90];
int d[110][110][90], end;

int f(int x, int y, int lv)
{
	if(d[x][y][lv] == -1)
	{
		if(lv == end-1)
			d[x][y][lv] = 1;
		else
		{
			d[x][y][lv] = 0;
			for(int i=-k; i<=k; i++)
			{
				if(i==0 || x+i<0 || x+i>=n)
					continue;
				if(a[x+i][y] == b[lv+1])
					d[x][y][lv] += f(x+i, y, lv+1);
			}
			for(int j=-k; j<=k; j++)
			{
				if(j==0 || y+j<0 || y+j>=m)
					continue;
				if(a[x][y+j] == b[lv+1])
					d[x][y][lv] += f(x, y+j, lv+1);
			}
		}
	}
	return d[x][y][lv];
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<n; i++)
		scanf("%s", a[i]);
	scanf("%s", b);

	end = (int)strlen(b);
	memset(d, -1, sizeof(d));

	int res = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(a[i][j] == b[0])
				res += f(i, j, 0);
	printf("%d", res);
}
