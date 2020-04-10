#include <cstdio>
#include <algorithm>
#define N 1010
#define R 10007

using namespace std;

int n, k;
int d[N][N];

int f(int r, int c)
{
	c = min(c, r-c);
	if(c == 0)
		return 1;
	if(!d[r][c])
		d[r][c] = (f(r-1,c-1)+f(r-1,c))%R;
	return d[r][c];
}

int main()
{
	scanf("%d %d", &n, &k);
	printf("%d", f(n, k));
	return 0;
}
