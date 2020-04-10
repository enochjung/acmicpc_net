#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 210
#define K 210
#define R 1000000000

using namespace std;

int n, k, d[N][K];

int f(int x, int y)
{
	if(x==0 || y==1)
		return 1;
	if(d[x][y] == -1)
	{
		d[x][y] = 0;
		for(int i=0; i<=min(n,x); ++i)
			d[x][y] = (d[x][y]+f(x-i,y-1))%R;
	}

	return d[x][y];
}

int main()
{
	scanf("%d %d", &n, &k);
	memset(d, -1, sizeof(d));
	printf("%d", f(n, k));
	return 0;
}
