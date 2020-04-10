#include <cstdio>

int a, b, d[1010];
int res;

int main()
{
	scanf("%d %d", &a, &b);
	for(int i=0;; i++)
	{
		bool check = false;
		for(int j=0; j<=i; j++)
		{
			d[i*(i+1)/2+j] = i+1;
			if(i*(i+1)/2+j == b-1)
			{
				check = true;
				break;
			}
		}
		if(check)
			break;
	}

	for(int i=a-1; i<b; i++)
		res += d[i];
	printf("%d\n", res);
	return 0;	
}
