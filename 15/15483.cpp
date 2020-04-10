#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010

using namespace std;

char a[N], b[N];
int n, m, d[N][N];

int main()
{
	scanf("%s %s", a, b);
	n = (int)strlen(a);
	m = (int)strlen(b);

	for(int i=1; i<=n; ++i)
		d[i][0] = i;
	for(int j=1; j<=m; ++j)
		d[0][j] = j;

	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			d[i][j] = a[i-1]==b[j-1]? d[i-1][j-1] : min({d[i-1][j],d[i][j-1],d[i-1][j-1]})+1;

	printf("%d", d[n][m]);
	return 0;
}
