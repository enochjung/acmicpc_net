#include <cstdio>
#include <cstdlib>
#define N 200010

int n, a[N];
int res_a, res_b;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	res_a = a[0];
	res_b = a[n-1];
	for(int i=0,j=n-1; i<j;)
	{
		if(abs(a[i]+a[j]) < abs(res_a+res_b))
		{
			res_a = a[i];
			res_b = a[j];
		}

		if(a[i]+a[j] > 0)
			--j;
		else
			++i;
	}

	printf("%d %d", res_a, res_b);
	return 0;
}