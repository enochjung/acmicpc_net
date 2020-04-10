#include <stdio.h>
#include <math.h>

int n;
int d[100010];

int f(int x)
{
	if(x == 0)
		return 0;

	if(d[x] == 0)
	{
		int min = 999999;
		for(int i=(int)sqrt(x); i>=1; i--)
		{
			int res = f(x-i*i);
			if(min > res)
				min = res;
		}
		d[x] = min+1;
	}

	return d[x];
}

int main()
{
	scanf("%d", &n);
	printf("%d", f(n));
	return 0;
}
