#include <cstdio>
#include <algorithm>
#define N 12

using namespace std;

int r, c;
char a[N][N];
bool b[N][N];
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};

int main()
{
	scanf("%d %d", &r, &c);
	for(int i=1; i<=r; ++i)
		scanf("%s", a[i]+1);

	int xs=99, xe=0, ys=99, ye=0;
	for(int i=1; i<=r; ++i)
		for(int j=1; j<=c; ++j)
			if(a[i][j] == 'X')
			{
				int cnt = 0;
				for(int w=0; w<4; ++w)
					if(a[i+dx[w]][j+dy[w]] != 'X')
						++cnt;
				if(cnt < 3)
				{
					b[i][j] = true;
					xs = min(xs, i);
					xe = max(xe, i);
					ys = min(ys, j);
					ye = max(ye, j);
				}
			}

	for(int i=xs; i<=xe; ++i)
	{
		for(int j=ys; j<=ye; ++j)
			printf("%c", b[i][j]? 'X' : '.');
		printf("\n");
	}
	return 0;
}
