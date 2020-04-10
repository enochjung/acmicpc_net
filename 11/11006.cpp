#include <cstdio>

int t, n, m;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d", &n, &m);
		printf("%d %d\n", m*2-n, n-m);
	}
	return 0;
}
