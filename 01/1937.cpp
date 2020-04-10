#include <stdio.h>

int n, a[510][510];
int d[510][510];
int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};

int f(int x, int y)
{
	if(d[x][y] == 0)
	{
		int max = 0;
		for(int i=0; i<4; i++)
		{
			int px = x+dx[i];
			int py = y+dy[i];
			if(0<=px && px<n && 0<=py && py<n && a[x][y]<a[px][py])
				if(max < f(px, py))
					max = f(px, py);
		}
		d[x][y] = max+1;
	}
	return d[x][y];
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &a[i][j]);

	int res = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(res < f(i, j))
				res = f(i, j);

	printf("%d", res);
	return 0;
}
