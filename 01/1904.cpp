#include <cstdio>
#define N 1000010
#define R 15746

int n, d[N]={1};

int f(int x)
{
	if(x < 0)
		return 0;
	if(d[x] == 0)
		d[x] = (f(x-1)+f(x-2))%R;
	return d[x];
}

int main()
{
	scanf("%d", &n);
	printf("%d", f(n));
	return 0;
}
