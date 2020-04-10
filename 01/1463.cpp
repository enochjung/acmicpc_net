#include <stdio.h>
#include <string.h>

int n;
unsigned int d[1000010];

inline int min(unsigned int a, unsigned int b)
{
	return a<b? a : b;
}

int main()
{
	memset(d, -1, sizeof(d));
	d[1] = 0;

	scanf("%d", &n);
	for(int i=1; i<n; i++)
	{
		if(i*3 <= n)
			d[i*3] = min(d[i*3], d[i]+1);
		if(i*2 <= n)
			d[i*2] = min(d[i*2], d[i]+1);
		if(i+1 <= n)
			d[i+1] = min(d[i+1], d[i]+1);
	}

	printf("%d", d[n]);

	return 0;
}
