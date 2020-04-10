#include <cstdio>
#include <algorithm>
#define N 100010

using namespace std;

int n, a[N];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);
	
	sort(a, a+n);

	int res = 0;
	for(int i=0; i<n; ++i)
		res = max(res, a[i]*(n-i));
	printf("%d", res);
	return 0;
}
