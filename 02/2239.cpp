#include <cstdio>
#include <cstdlib>
#define N 9

int b[N][N];

void f(int x, int y)
{
	if (x == N)
	{
		for (int i=0; i<N; ++i)
		{
			for (int j=0; j<N; ++j)
				printf("%d", b[i][j]);
			printf("\n");
		}
		exit(0);
	}
	if (y == N)
	{
		f(x+1, 0);
		return;
	}
	if (b[x][y] != 0)
	{
		f(x, y+1);
		return;
	}
	for (int v=1; v<=N; ++v)
	{
		bool flag = true;
		for (int i=0; i<N && flag; ++i)
			if (b[x][i]==v || b[i][y]==v || b[x/3*3+i/3][y/3*3+i%3]==v)
				flag = false;
		if (flag)
		{
			b[x][y] = v;
			f(x, y+1);
			b[x][y] = 0;
		}
	}
}

int main()
{
	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			scanf("%1d", &b[i][j]);

	f(0, 0);

	return 0;
}