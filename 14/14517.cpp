#include <cstdio>
#include <cstring>
#define N 1010
#define R 10007

int n;
char a[N];
bool d[N][N];

int f(int x, int y)
{
	if(!d[x][y])
	{
		d[x][y] = true;

		if(x == y)
			return 1;
		if(x > y)
			return 0;
		if(a[x] == a[y])
			return 1+f(x+1,y-1)+f(x,y-1)+f(x+1,y);
		else
			return f(x,y-1)+f(x+1,y);
	}
	return 0;
}

int main()
{
	scanf("%s", a);
	n = strlen(a);

	printf("%d", f(0,n-1));
	return 0;
}
