#include <cstdio>

int a, b, c, d, e, f;

int gcd(int x, int y)
{
	while(x%y)
	{
		int t = x%y;
		x = y;
		y = t;
	}
	return y;
}

int main()
{
	scanf("%d %d %d %d", &a, &b, &c, &d);

	e = a*d + b*c;
	f = b*d;

	int g = gcd(e, f);

	printf("%d %d\n", e/g, f/g);
	return 0;
}
