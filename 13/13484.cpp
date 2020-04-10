#include <cstdio>

int x, n;

int main()
{
	scanf("%d %d", &x, &n);

	int res = x*(n+1);
	while(n--)
	{
		int v;
		scanf("%d", &v);
		res -= v;
	}

	printf("%d", res);
	return 0;
}
