#include <stdio.h>

char a[110];

int main()
{
	while(fgets(a, sizeof(a), stdin) != 0)
		printf("%s", a);
	return 0;
}
