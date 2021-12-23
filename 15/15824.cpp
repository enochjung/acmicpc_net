#include <cstdio>
#include <algorithm>
#define N 300000
#define R 1000000007

using namespace std;

int n, a[N];

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);

	long long res = 0;
	long long mul = 2;
	long long sum = 0;
	for (int i=1; i<n; ++i)
	{
		sum = (sum*2 + (a[i]-a[i-1])*(mul-1)) % R;
		res = (res + sum) % R;
		mul = (mul * 2) % R;
	}

	printf("%lld\n", res);
	return 0;
}