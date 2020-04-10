#include <cstdio>
#include <algorithm>

using namespace std;

int t, k, n;

int f(int x, int y)
{
	int res = 1;
	for(int i=1; i<=y; i++)
	{
		res *= x-i+1;
		res /= i;
	}
	return res;
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d", &k, &n);
		printf("%d\n", f(k+n, min(n-1,k+1)));
	}
	return 0;
}
