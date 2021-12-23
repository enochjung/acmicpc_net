#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);

	if (n % 2 == 1)
		printf("%d %d\n", (n + 1) / 2, (n - 1) / 2);
	else if (n % 4 == 0)
		printf("%d %d\n", n / 4 + 1, n / 4 - 1);
	else
		printf("impossible\n");

	return 0;
}