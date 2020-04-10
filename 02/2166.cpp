#include <stdio.h>

int n;
int x[10010], y[10010];

long long outer(int x1, int y1, int x2, int y2)
{
	return 1LL*x1*y2 - 1LL*x2*y1;
}

long long abs(long long v)
{
	return v>0? v : -v;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %d", x+i, y+i);

	long long res = 0;
	
	for(int i=1; i<n-1; i++)
		res += outer(x[i]-x[0], y[i]-y[0], x[i+1]-x[0], y[i+1]-y[0]);

	printf("%lld", abs(res)/2);
	printf(".%d", res&1? 5 : 0);
	return 0;
}
