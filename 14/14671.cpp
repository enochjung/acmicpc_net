#include <cstdio>

int k;
bool g[2][2];

int main()
{
	scanf("%*d %*d %d", &k);
	while(k--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		g[x&1][y&1] = true;
	}
	printf("%s", g[0][0]&&g[0][1]&&g[1][0]&&g[1][1]? "YES" : "NO");
	return 0;
}
