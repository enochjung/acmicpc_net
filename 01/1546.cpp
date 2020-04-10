#include <cstdio>

int n, a[1010], m;
double sum;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", a+i);
		if(m < a[i])
			m = a[i];
	}

	for(int i=0; i<n; i++)
		sum += (double)a[i]/m*100;
	printf("%.2lf\n", sum/n);
	return 0;
}
