#include <stdio.h>

int n, a[1010];
int d[1010];

int f(int x)
{
	if(d[x] == 9999)
	{
		int min = 9998;
		for(int i=x+1; i<n && i<=x+a[x]; i++)
			if(min > f(i))
				min = f(i);
		d[x] = min+1;
	}
	return d[x];
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", a+i);
		d[i] = 9999;
	}

	d[n-1] = 0;

	printf("%d", f(0)<9999? f(0) : -1);
	return 0;
}
