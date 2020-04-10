#include <cstdio>

int t, a, b;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", a+b);
	}
	return 0;
}
