#include <cstdio>
#include <algorithm>
#define N 21
#define A 26

using namespace std;

int r, c;
char a[N][N];
bool v[A];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int f(int x, int y, int p)
{
	int ret = p;
	for (int w=0; w<4; ++w)
	{
		int tx = x+dx[w];
		int ty = y+dy[w];

		if (0<=tx && tx<r && 0<=ty && ty<c && !v[a[tx][ty]-'A'])
		{
			v[a[tx][ty]-'A'] = true;
			ret = max(ret, f(tx, ty, p+1));
			v[a[tx][ty]-'A'] = false;
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d", &r, &c);
	for (int i=0; i<r; ++i)
		scanf("%s", a[i]);
	
	v[a[0][0]-'A'] = true;
	printf("%d\n", f(0, 0, 1));
	return 0;
}