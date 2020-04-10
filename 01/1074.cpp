#include <cstdio>

int n, r, c;

int f(int s, int x, int y)
{
	if(s == 0)
		return 0;

	int h = 1<<(s-1);
	return (x<h?0:h*h*2) + (y<h?0:h*h) + f(s-1, x%h, y%h);
}

int main()
{
	scanf("%d %d %d", &n, &r, &c);
	printf("%d\n", f(n, r, c));
	return 0;
}
