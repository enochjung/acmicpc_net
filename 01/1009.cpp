#include <stdio.h>
#include <math.h>

int t, a, b, r;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d", &a, &b);
		a %= 10;
		b = (b+3)%4+1;
		r = ((int)pow(a, b))%10;
		printf("%d\n", r>0? r : 10);
	}
	return 0;
}
