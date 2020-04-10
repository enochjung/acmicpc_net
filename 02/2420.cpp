#include <stdio.h>

long long int n, m;

int main()
{
	scanf("%lld %lld", &n, &m);
	printf("%lld", n>m? n-m : m-n);
}
