#include <cstdio>
#include <algorithm>
#define N 500000

using namespace std;

int n, d[N], len;

int main()
{
	scanf("%d", &n);

	long long res = 0;
	while (n--)
	{
		int a;
		scanf("%d", &a);

		int lower = (int)(lower_bound(d, d+len, -a) - d);
		int upper = (int)(upper_bound(d, d+len, -a) - d);

		res += len - max(lower-1, 0);
		d[upper] = -a;
		len = upper+1;
	}

	printf("%lld\n", res);
	return 0;
}