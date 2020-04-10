#include <cstdio>
#define N 2190

int n, a[N][N], res[3];

bool is_same(int x, int y, int s)
{
	for(int i=x; i<x+s; ++i)
		for(int j=y; j<y+s; ++j)
			if(a[i][j] != a[x][y])
				return false;
	return true;
}

void f(int x, int y, int s)
{
	if(is_same(x, y, s))
		++res[a[x][y]+1];
	else
	{
		int ss = s/3;
		for(int i=0; i<3; ++i)
			for(int j=0; j<3; ++j)
				f(x+i*ss, y+j*ss, ss);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			scanf("%d", &a[i][j]);

	f(0, 0, n);
	for(int i=0; i<3; ++i)
		printf("%d\n", res[i]);
	return 0;
}
