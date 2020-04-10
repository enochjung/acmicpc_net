#include <stdio.h>

bool a[10010];

int main()
{
	for(int i=1; i<=10000; i++)
	{
		int v=i, sum=i;
		
		while(v)
		{
			sum += v%10;
			v /= 10;
		}
		
		if(sum <= 10000)
			a[sum] = true;
		
		if(!a[i])
			printf("%d\n", i);
	}

	return 0;
}
