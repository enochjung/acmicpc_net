#include <cstdio>
#include <algorithm>

using namespace std;

int r, c, a[110][110];
int d[110][110];

int main()
{
	scanf("%d %d", &r, &c);
	for(int i=1; i<=r; i++)
		for(int j=1; j<=c; j++)
			scanf("%d", &a[i][j]);

	for(int i=0; i<=r+1; i++)
		for(int j=0; j<=c+1; j++)
			d[i][j] = -99999;
	d[1][1] = a[1][1];
	for(int j=2; j<=c; j++)
		for(int i=1; i<=r; i++)
			d[i][j] = max(d[i-1][j-1], max(d[i][j-1], d[i+1][j-1])) + a[i][j];

	printf("%d\n", d[r][c]);
	return 0;
}
