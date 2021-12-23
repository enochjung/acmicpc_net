#include <cstdio>
#define N ('Z'+1)

int n;
char l[N], r[N];

void f(char c, int t)
{
	if (c == '.')
		return;

	if (t == 0)
		putchar(c);
	f(l[c], t);
	if (t == 1)
		putchar(c);
	f(r[c], t);
	if (t == 2)
		putchar(c);
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		char a, b, c;
		scanf(" %c %c %c", &a, &b, &c);
		l[a] = b;
		r[a] = c;
	}

	f('A', 0);
	putchar('\n');
	f('A', 1);
	putchar('\n');
	f('A', 2);
	putchar('\n');
	return 0;
}