#include <stdio.h>
#include <math.h>

int t;
long long d, k;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		d = y-x;
		k = (long long)((sqrt(d*4+1)-2)/2);
		while((k+1)*(k+2) <= d)
			k++;
		d -= k*(k+1);
		if(d == 0)
			printf("%lld\n", k*2);
		else if(d <= k+1)
			printf("%lld\n", k*2+1);
		else
			printf("%lld\n", k*2+2);
	}
	return 0;
}
