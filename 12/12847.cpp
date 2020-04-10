#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a[100010];
long long sum, res;

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	for(int i=0; i<m; ++i)
		sum += a[i];
	res = sum;
	for(int i=m; i<n; ++i)
	{
		sum += a[i] - a[i-m];
		res = max(res, sum);
	}
	printf("%lld", res);
	return 0;
}
