#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[500010];
long long res;

int abs(int x)
{
	return x>0? x : -x;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);

	for(int i=0; i<n; ++i)
		res += abs(a[i]-i-1);

	printf("%lld", res);
	return 0;
}
