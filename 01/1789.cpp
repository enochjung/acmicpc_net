#include <cstdio>
#include <cmath>
#define ERROR (1e-9)

long long s;

int main()
{
	scanf("%lld", &s);

	printf("%d\n", (int)((sqrt(s*8+1)-1)/2+ERROR));
	return 0;
}
