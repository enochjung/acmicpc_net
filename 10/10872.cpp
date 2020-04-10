#include <cstdio>

int n;
int res = 1;

int main()
{
	scanf("%d", &n);
	for(int i=2; i<=n; i++)
		res *= i;
	printf("%d\n", res);
	return 0;
}
