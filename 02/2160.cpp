#include <cstdio>

int n;
char p[50][5][10];

int compare(int x, int y)
{
	int cnt = 0;
	for(int i=0; i<5; ++i)
		for(int j=0; j<7; ++j)
			if(p[x][i][j] != p[y][i][j])
				++cnt;
	return cnt;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		for(int j=0; j<5; ++j)
			scanf("%s", p[i][j]);

	int min = 99;
	int a, b;
	for(int i=0; i<n-1; ++i)
		for(int j=i+1; j<n; ++j)
		{
			int ret = compare(i, j);
			if(min > ret)
			{
				min = ret;
				a = i;
				b = j;
			}
		}
	printf("%d %d", a+1, b+1);
	return 0;
}
