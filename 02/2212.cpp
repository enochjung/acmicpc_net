#include <cstdio>
#include <algorithm>
#define N 10010

using namespace std;

int n, k, a[N], b[N];

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);
	int res = a[n-1]-a[0];
	for(int i=0; i<n-1; ++i)
		b[i] = a[i+1]-a[i];
	
	sort(b, b+n-1);
	for(int i=n-2; i>=max(0,n-k); --i)
		res -= b[i];
	printf("%d", res);

	return 0;
}
