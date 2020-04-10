#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1510

using namespace std;

int n, m;
char a[N], b[N];
int d[N][N];

int f(int x, int y)
{
	if(x<0 || y<0)
		return 0;

	if(d[x][y] == -1)
	{
		d[x][y] = 0;
		if(a[x] == b[y])
			d[x][y] = max(d[x][y], f(x-1,y-1)+1);
		if(a[x] == b[y-f(x-1,y)])
			d[x][y] = max(d[x][y], f(x-1,y)+1);
		if(a[x-f(x,y-1)] == b[y])
			d[x][y] = max(d[x][y], f(x,y-1)+1);
	}
	return d[x][y];
}

int main()
{
	scanf("%s %s", a, b);
	n = (int)strlen(a);
	m = (int)strlen(b);

	memset(d, -1, sizeof(d));
	
	int res = 0;
	for(int i=1; i<n; ++i)
		for(int j=1; j<m; ++j)
			res = max(res, f(i, j));
	printf("%d", res);
	return 0;
}
