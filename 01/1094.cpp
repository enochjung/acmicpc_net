#include <cstdio>

int x;

int f(int x)
{
	int cnt = 0;
	while(x)
	{
		x -= x&-x;
		++cnt;
	}
	return cnt;
}

int main()
{
	scanf("%d", &x);
	printf("%d", f(x));
	return 0;
}
