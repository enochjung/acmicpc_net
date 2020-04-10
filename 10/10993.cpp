#include <cstdio>
#include <cstdlib>

int n;
bool a[1030][2050];

void star(int s, int x, int y)
{
	if(s & 1)
	{
		for(int i=0; i<(1<<(s+1))-3; i++)
		{
			a[x+(1<<s)-2][y+i] = 1;
			a[x+abs((1<<s)-2-i)][y+i] = 1;
		}
	}
	else
	{
		for(int i=0; i<(1<<(s+1))-3; i++)
		{
			a[x][y+i] = 1;
			a[x+(1<<s)-2-abs((1<<s)-2-i)][y+i] = 1;
		}
	}

	if(s > 1)
	{
		if(s & 1)
			star(s-1, x+(1<<(s-1))-1, y+(1<<(s-1)));
		else
			star(s-1, x+1, y+(1<<(s-1)));
	}
}

int main()
{
	scanf("%d", &n);

	star(n, 0, 0);
	
	for(int i=0; i<(1<<n)-1; i++)
	{
		int last = 0;
		for(int j=0; j<(1<<(n+1))-3; j++)
			if(a[i][j])
				last = j;
		for(int j=0; j<=last; j++)
			printf("%c", a[i][j]? '*' : ' ');
		printf("\n");
	}
	return 0;
}
