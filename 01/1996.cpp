#include <cstdio>
#define N 1010

int n;
char a[N][N], b[N][N];
int dx[]={-1, 0, 1, 1, 1, 0, -1, -1}, dy[]={-1, -1, -1, 0, 1, 1, 1, 0};

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		scanf("%s", a[i]+1);

	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
		{
			if(a[i][j] == '.')
			{
				int sum = 0;
				for(int w=0; w<8; ++w)
				{
					int tx = i+dx[w];
					int ty = j+dy[w];
					if('1'<=a[tx][ty] && a[tx][ty]<='9')
						sum += a[tx][ty]-'0';
				}
				b[i][j] = sum>9? 'M' : '0'+sum;
			}
			else
				b[i][j] = '*';
		}
	
	for(int i=1; i<=n; ++i)
		printf("%s\n", b[i]+1);
	return 0;
}
