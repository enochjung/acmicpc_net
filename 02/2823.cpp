#include <cstdio>

int r, c;
char b[20][20];
int dx[]={-1, 0, 1, 0}, dy[]={0, -1, 0, 1};

int main()
{
	for(int i=0; i<12; ++i)
		for(int j=0; j<12; ++j)
			b[i][j] = 'X';

	scanf("%d %d", &r, &c);
	for(int i=1; i<=r; ++i)
		for(int j=1; j<=c; ++j)
			scanf(" %c", &b[i][j]);

	int res = 0;
	for(int i=1; i<=r; ++i)
		for(int j=1; j<=c; ++j)
			if(b[i][j] == '.')
			{
				int cnt = 0;
				for(int w=0; w<4; ++w)
					if(b[i+dx[w]][j+dy[w]] == 'X')
						++cnt;
				if(cnt > 2)
					res |= 1;
			}
	printf("%d", res);
	return 0;
}
