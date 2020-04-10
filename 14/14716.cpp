#include <cstdio>

int m, n, a[260][260];
int dx[8]={-1,-1,-1,0,0,1,1,1}, dy[8]={-1,0,1,-1,1,-1,0,1};

void f(int x, int y)
{
	a[x][y] = 0;
	for(int k=0; k<8; k++)
	{
		int nx = x+dx[k];
		int ny = y+dy[k];

		if(0<=nx && nx<m && 0<=ny && ny<n && a[nx][ny])
			f(nx, ny);
	}
}

int main()
{
	scanf("%d %d", &m, &n);
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &a[i][j]);

	int res = 0;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			if(a[i][j])
			{
				f(i, j);
				res++;
			}

	printf("%d\n", res);
	return 0;
}
