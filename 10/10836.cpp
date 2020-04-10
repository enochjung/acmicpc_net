#include <cstdio>
#include <algorithm>
#define N 710

using std::max;

int m, n;
int p[N*2], q[N], r[N][N];

int main()
{
	scanf("%d %d", &m, &n);
	while(n--)
	{
		int a, b;
		scanf("%d %d %*d", &a, &b);
		b += a;

		++p[a], ++p[b];
		++q[max(0,a-m)], ++q[max(0,b-m)];

		// 0 : 0 - a-1
		// 1 : a - b-1
		// 2 : b - 2m-2
		//
		// 0 - a-1-m
		// 1 : a-m - b-1-m
		// 2 : b-m - m-2
	}

	int x, y;
	int sum;

	x=m-1, y=0;
	sum = 0;
	for(int i=0; i<m*2-1; ++i)
	{
		sum += p[i];
		r[x][y] = sum;
		x==0? ++y : --x;
	}
	sum = 0;
	for(int i=0; i<m-1; ++i)
	{
		sum += q[i];
		r[1][i+1] = sum;
	}

	for(int i=0; i<m; ++i)
	{
		for(int j=0; j<m; ++j)
			printf("%d ", r[i&&j? 1 : i][j]+1);
		printf("\n");
	}
	return 0;
}
