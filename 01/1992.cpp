#include <cstdio>
#define N 64

int n, a[N][N];

bool is_same(int size, int x, int y)
{
	for (int i=0; i<size; ++i)
		for (int j=0; j<size; ++j)
			if (a[i+x][j+y] != a[x][y])
				return false;
	return true;
}

void f(int size, int x, int y)
{
	if (is_same(size, x, y))
		printf("%d", a[x][y]);
	else
	{
		int s = size/2;
		printf("(");
		f(s, x, y);
		f(s, x, y+s);
		f(s, x+s, y);
		f(s, x+s, y+s);
		printf(")");
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			scanf("%1d", &a[i][j]);

	f(n, 0, 0);
	return 0;
}