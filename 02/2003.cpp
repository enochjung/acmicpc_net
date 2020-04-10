#include <stdio.h>

int n, m, a[10010];
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);

	int sum = 0;
	for(int i=0,j=0; j<n; j++)
	{
		sum += a[j];
		while(sum > m)
			sum -= a[i++];
		if(sum == m)
			res++;
	}

	printf("%d", res);
	return 0;
}
