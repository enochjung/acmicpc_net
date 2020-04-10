#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010

using namespace std;

int n, m;
char a[N], b[N];
int d[N][N], p, q;

int f(int x, int y)
{
	if(x<0 || y<0)
		return 0;

	if(d[x][y] == -1)
	{
		d[x][y] = 0;
		d[x][y] = max(d[x][y], f(x-1,y)-2);
		d[x][y] = max(d[x][y], f(x,y-1)-2);
		d[x][y] = max(d[x][y], f(x-1,y-1)+(a[x]==b[y]? 3 : -2));

		if(d[p][q] < d[x][y])
			p=x, q=y;
	}

	return d[x][y];
}

int main()
{
	scanf("%d %s %d %s", &n, a, &m, b);
	memset(d, -1, sizeof(d));

	f(n-1, m-1);

	int i=p, j=q;
	while(true)
	{
		if(d[i][j] == d[i-1][j]-2)
			i--;
		else if(d[i][j] == d[i][j-1]-2)
			j--;
		else if(d[i-1][j-1] == 0)
			break;
		else
			i--, j--;
	}

	printf("%d\n", d[p][q]);
	for(; i<=p; i++)
		printf("%c", a[i]);
	printf("\n");
	for(; j<=q; j++)
		printf("%c", b[j]);

	return 0;
}
