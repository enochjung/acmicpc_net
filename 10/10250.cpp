#include <cstdio>

int t, h, n;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %*d %d", &h, &n);
		printf("%d%02d\n", (n-1)%h+1, (n-1)/h+1);
	}
	return 0;
}
