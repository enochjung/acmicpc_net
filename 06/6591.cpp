#include <cstdio>
#include <algorithm>

using namespace std;

long long n, k;
long long res;

int main()
{
	while(1)
	{
		scanf("%lld %lld", &n, &k);
		if(n==0 && k==0)
			break;

		res = 1;
		k = min(k, n-k);
		for(int i=1; i<=k; i++)
		{
			res *= n-i+1;
			res /= i;
		}
	
		printf("%lld\n", res);
	}
	return 0;
}
