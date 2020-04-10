#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
#define M 10
#define INF 999999

using namespace std;

int n, m, a[N], s[N];
int d[N][N][M];

int f(int i, int j, int k)
{
	if(i == n)
		return 0;
	if(d[i][j][k] == -1)
		d[i][j][k] = min(f(i+1,j,k), k>0? f(i+1,i+1,k-1) : INF) + (s[i]-s[j])*a[i];
	return d[i][j][k];
}

void g(int i, int j, int k)
{
	if(i == n)
		return;
	if(k>0 && f(i+1,i+1,k-1) <= f(i+1,j,k))
	{
		printf("%d ", i+1);
		g(i+1, i+1, k-1);
	}
	else
		g(i+1, j, k);
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", a+i);
		s[i+1] = s[i]+a[i];
	}
	if(n == m)
	{
		printf("0\n");
		for(int i=0; i<n; ++i)
			printf("%d ", i+1);
		return 0;
	}

	memset(d, -1, sizeof(d));
	printf("%d\n", f(0, 0, m));
	g(0, 0, m);
	return 0;
}
