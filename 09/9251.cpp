#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m, d[2][1010];
char a[1010], b[1010];

int main()
{
	scanf("%s %s", a, b);
	n = (int)strlen(a);
	m = (int)strlen(b);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			d[1-i&1][j+1] = a[i]==b[j]? d[i&1][j]+1 : max(d[1-i&1][j],d[i&1][j+1]);

	printf("%d\n", d[n&1][m]);
	return 0;
}
