#include <stdio.h>

int y, m, s, t;

int main()
{
	scanf("%d %d %d %d", &y, &m, &s, &t);

	s += t;

	m += s/60;
	s %= 60;

	y += m/60;
	m %= 60;

	y %= 24;

	printf("%d %d %d\n", y, m, s);
	return 0;
}
