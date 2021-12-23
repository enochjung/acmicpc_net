#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10

int c, n, m;
char table[N][N+1];
int d[N][1<<N];

int count_bit(int col, int bit)
{
	int cnt = 0;

	for (int i=0; i<n; ++i)
	{
		int val = 1<<i;
		if (bit&val && table[i][col]=='.')
			++cnt;
	}

	return cnt;
}

int f(int x, int y)
{
	if (d[x][y] == -1)
	{
		if (x == 0)
			d[x][y] = count_bit(x, y);
		else
		{
			d[x][y] = f(x-1, (1<<n)-1-(y|(y>>1)|((y<<1)%(1<<n)))) + count_bit(x, y);
			for (int i=0; i<n; ++i)
			{
				int val = 1<<i;
				if (y & val)
					d[x][y] = std::max(d[x][y], f(x, y-val));
			}
		}
	}

	return d[x][y];
}

int main()
{
	for (scanf("%d",&c); c--;)
	{
		memset(d, -1, sizeof(d));

		scanf("%d %d", &n, &m);
		for (int i=0; i<n; ++i)
			scanf("%s", table[i]);

		printf("%d\n", f(m-1, (1<<n)-1));
	}
	
	return 0;
}