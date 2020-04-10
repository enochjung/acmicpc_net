#include <stdio.h>

int a, b;

int main()
{
	scanf("%d %d", &a, &b);
	printf("%d\n%d\n%d\n%d\n%d\n", a+b, a-b, a*b, a/b, a%b);
	return 0;
}
