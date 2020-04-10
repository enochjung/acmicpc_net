#include <cstdio>

int a, b;

int main()
{
	scanf("%d %d", &a, &b);
	printf("%c", a%30*12==b? 'O' : 'X');
	return 0;
}
