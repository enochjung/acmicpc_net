#include <cstdio>

int n;
bool a[410][410];

int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

int main()
{
	scanf("%d", &n);

	int way = 0;
	int x=0, y=(n-1)*4;
	bool turn = 0;

	if(n == 1)
	{
		printf("*");
		return 0;
	}

	while(1)
	{
		a[x][y] = 1;

		int nx = x+dx[way];
		int ny = y+dy[way];
		int nnx = x+dx[way]*2;
		int nny = y+dy[way]*2;

		if(nx<0 || nx>=n*4-1 || ny<0 || ny>=n*4-3 || a[nnx][nny])
		{
			if(turn)
				break;
			turn = 1;
			way = (way+1)%4;
		}
		else
		{
			turn = 0;
			x += dx[way];
			y += dy[way];
		}
	}

	for(int i=0; i<n*4-1; i++)
	{
		int last = 0;
		for(int j=0; j<n*4-3; j++)
			if(a[i][j])
				last = j;
		for(int j=0; j<=last; j++)
			printf("%c", a[i][j]? '*' : ' ');
		printf("\n");
	}
	return 0;
}
