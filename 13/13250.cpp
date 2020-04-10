#include <cstdio>
#define N 1000020

int n;
double d[N] = {0,0,0,0,0,1};

int main()
{
	scanf("%d", &n);
	for(int i=6; i<=n+4; ++i)
		d[i] = (d[i-6]+d[i-5]+d[i-4]+d[i-3]+d[i-2]+d[i-1]) / 6 + 1;
	printf("%.10lf", d[n+4]);
	return 0;
}
