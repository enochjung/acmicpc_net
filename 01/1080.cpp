#include <cstdio>
#define N 60

int n, m;
char a[N][N], b[N][N];

void change(int x, int y)
{
	a[x][y] = '0'+'1'-a[x][y];
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%s", a[i]);
	for(int i=0; i<n; ++i)
		scanf("%s", b[i]);

	int res = 0;
	for(int i=0; i<n-2; ++i)
		for(int j=0; j<m-2; ++j)
			if(a[i][j] != b[i][j])
			{
				++res;
				for(int p=0; p<3; ++p)
					for(int  q=0; q<3; ++q)
						change(i+p, j+q);
			}

	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(a[i][j] != b[i][j])
			{
				printf("-1");
				return 0;
			}
	printf("%d", res);
	return 0;
}
