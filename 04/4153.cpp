#include <cstdio>
#include <algorithm>

bool f(int a, int b, int c)
{
	if (a > b)
		std::swap(a, b);
	if (a > c)
		std::swap(a, c);
	if (b > c)
		std::swap(b, c);

	return a*a + b*b == c*c;
}

int main()
{
	int a, b, c;

	while (true)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0)
			break;

		printf("%s\n", f(a, b, c) ? "right" : "wrong");
	}

	return 0;
}