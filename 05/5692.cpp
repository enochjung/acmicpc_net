#include <cstdio>

int n;
int v[5] = {1,2,6,24,120};

int f(int x, int lv)
{
	if(x == 0)
		return 0;
	return x%10*v[lv] + f(x/10,lv+1);
}

int main()
{
	while(scanf("%d",&n) && n)
	{
		printf("%d\n", f(n,0));
	}

	return 0;
}
