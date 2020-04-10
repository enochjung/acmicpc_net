#include <stdio.h>

int n, res;

int main()
{
	scanf("%d", &n);

	res = (n<100? n : 99);
	for(int i=100; i<=n; i++)
	{
		int v = i;
		int a, r;
		bool flag = true;

		a = (v/10)%10;
		r = v%10-a;
		v /= 100;

		while(v)
		{
			if(v%10 != a-r)
			{
				flag = false;
				break;
			}
			a = a-r;
			v /= 10;
		}
		
		if(flag)
			res++;
	}

	printf("%d", res);

	return 0;
}
