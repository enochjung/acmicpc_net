#include <cstdio>
#define MOD 10007

int n;
int d[1010] = {1, 1};

int main()
{
	scanf("%d", &n);
	for(int i=2; i<=n; ++i)
		d[i] = (d[i-1]+d[i-2]*2)%MOD;
	printf("%d", d[n]);
	return 0;
}
