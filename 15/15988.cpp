#include <cstdio>
#define N 1000010
#define R 1000000009

int t, d[N]={1};

int f(int x)
{
	if(x < 0)
		return 0;
	if(d[x] == 0)
		d[x] = (0LL+f(x-1)+f(x-2)+f(x-3))%R;
	return d[x];
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		int v;
		scanf("%d", &v);
		printf("%d\n", f(v));
	}

	return 0;
}
