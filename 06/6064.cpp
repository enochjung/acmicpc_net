#include <stdio.h>

int t, m, n, x, y;

int gcd(int a, int b)
{
	if(a%b == 0)
		return b;
	return gcd(b, a%b);
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d %d %d", &m, &n, &x, &y);
		x--, y--;
		
		int last = m*n/gcd(m,n);
		int res;

		for(res=x; res<last; res+=m)
			if(res%n == y)
				break;

		if(res < last)
			printf("%d\n", res+1);
		else
			printf("-1\n");
	}

	return 0;
}
