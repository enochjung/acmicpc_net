#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2510

using namespace std;

int n, d[N], p[N][N];
char s[N];

bool f(int x, int y)
{
	if(p[x][y] == -1)
	{
		if(x >= y)
			p[x][y] = 1;
		else if(s[x] == s[y])
			p[x][y] = f(x+1, y-1);
		else
			p[x][y] = 0;
	}
	return p[x][y];
}

int main()
{
	memset(p, -1, sizeof(p));

	scanf("%s", s+1);
	n = (int)strlen(s+1);

	for(int i=1; i<=n; i++)
	{
		d[i] = 9999;
		for(int j=1; j<=i; j++)
			if(f(j, i))
				d[i] = min(d[i], d[j-1]+1);
	}
	printf("%d\n", d[n]);
	return 0;
}
