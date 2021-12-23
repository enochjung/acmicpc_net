#include <cstdio>

int a, b, c;

int f(int x)
{
	if(x == 1)
		return a;
	if(x&1)
		return 1LL*f(x-1)*a%c;
	int ret = f(x/2);
	return 1LL*ret*ret%c;
}

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", f(b));
	return 0;
}
