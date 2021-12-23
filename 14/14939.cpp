#include <cstdio>
#define N 10

char a[N][N+1];
bool b[N][N];

void press(int x, int y)
{
	int dx[] = {0,-1, 0, 1, 0};
	int dy[] = {0, 0,-1, 0, 1};

	for (int w=0; w<5; ++w)
	{
		int tx = x+dx[w];
		int ty = y+dy[w];

		if (0<=tx && tx<N && 0<=ty && ty<N)
			b[tx][ty] = !b[tx][ty];
	}
}

int f(int p)
{
	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			b[i][j] = a[i][j]=='O';

	int cnt = 0;
	for (int j=0; j<N; ++j)
		if (((1<<j)&p) > 0)
		{
			++cnt;
			press(0, j);
		}

	for (int i=1; i<N; ++i)
		for (int j=0; j<N; ++j)
			if (b[i-1][j])
			{
				++cnt;
				press(i, j);
			}

	for (int j=0; j<N; ++j)
		if (b[N-1][j])
			return -1;
	return cnt;
}

int main()
{
	for (int i=0; i<N; ++i)
		scanf("%s", a[i]);

	int res = -1;
	for (int p=0; p<(1<<N); ++p)
	{
		int val = f(p);
		if (val!=-1 && (res==-1 || res>val))
			res = val;
	}

	printf("%d\n", res);
	return 0;
}