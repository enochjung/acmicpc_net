#include <cstdio>
#include <cstring>
#define N 1010

char s[N];

int main()
{
	scanf("h%[e]y", s);

	int len = (int)strlen(s);

	putchar('h');
	for (int i = 0; i < len * 2; ++i)
		putchar('e');
	putchar('y');

	return 0;
}