#include <cstdio>
#include <cstdint>

char eevee[3][10] = {"Vaporeon", "Jolteon", "Flareon"};

int main()
{
	int *lv = new int;
	scanf("%d", lv);
	printf("%s", eevee[(intptr_t)lv%3]);
	delete lv;
	return 0;
}
