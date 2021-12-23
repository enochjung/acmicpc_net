#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 20

using namespace std;

int n;

void rotate(int b[N][N])
{
	int a[N][N];

	memcpy(a, b, sizeof(a));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			b[i][j] = a[n - 1 - j][i];
}

void move_left(const int b[N][N], int c[N][N])
{
	for (int i = 0; i < n; ++i)
	{
		int len = 0;
		bool merged = false;
		for (int j = 0; j < n; ++j)
		{
			if (b[i][j] != 0)
			{
				if (len > 0 && b[i][j] == c[i][len - 1] && !merged)
				{
					c[i][len - 1] <<= 1;
					merged = true;
				}
				else
				{
					c[i][len++] = b[i][j];
					merged = false;
				}
			}
		}
	}
}

int f(int b[N][N], int count)
{
	if (count == 0)
	{
		int val = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				val = max(val, b[i][j]);
		return val;
	}

	int val = 0;
	for (int d = 0; d < 4; ++d)
	{
		int c[N][N] = {};
		rotate(b);
		move_left(b, c);
		val = max(val, f(c, count - 1));
	}
	return val;
}

int main()
{
	int board[N][N];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &board[i][j]);

	printf("%d\n", f(board, 5));
	return 0;
}