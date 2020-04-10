#include <cstdio>

int a, b, c, d, e[10];

int main()
{
	scanf("%d %d %d", &a, &b, &c);

	d = a*b*c;
	while(d)
	{
		e[d%10]++;
		d /= 10;
	}

	for(int i=0; i<10; i++)
		printf("%d\n", e[i]);
	return 0;
}
