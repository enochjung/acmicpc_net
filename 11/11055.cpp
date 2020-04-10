#include <stdio.h>

int n;
int a[1010], d[1010], res;

int main()
{
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		int max = 0;
		scanf("%d", a+i);

		for(int j=0; j<i; j++)
			if(a[j]<a[i] && max<d[j])
				max = d[j];

		d[i] = max+a[i];

		if(res < d[i])
			res = d[i];
	}

	printf("%d", res);
	return 0;
}
