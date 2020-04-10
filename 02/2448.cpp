#include <cstdio>

int n;
bool a[3080][6150];

void star(int s, int x, int y)
{
	if(s == 3)
	{
		a[x][y+2] = 1;
		a[x+1][y+1] = a[x+1][y+3] = 1;
		a[x+2][y]=a[x+2][y+1]=a[x+2][y+2]=a[x+2][y+3]=a[x+2][y+4]=1;
	}
	else
	{
		star(s/2, x, y+s/2);
		star(s/2, x+s/2, y);
		star(s/2, x+s/2, y+s);
	}
}

int main()
{
	scanf("%d", &n);
	
	star(n, 0, 0);
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n*2-1; j++)
			printf("%c", a[i][j]? '*' : ' ');
		printf("\n");
	}
	return 0;
}
