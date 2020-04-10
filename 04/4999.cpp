#include <cstdio>
#include <cstring>

char a[1010], b[1010];

int main()
{
	scanf("%s %s", a, b);
	printf("%s\n", strlen(a)<strlen(b)? "no" : "go");
	return 0;
}
