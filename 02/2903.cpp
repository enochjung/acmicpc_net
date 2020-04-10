#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);
	printf("%d", ((1<<n)+1)*((1<<n)+1));
	return 0;
}
