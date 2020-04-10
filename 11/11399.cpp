#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[1010];
int res;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);

	sort(a, a+n);

	for(int i=0; i<n; i++)
		res += a[i]*(n-i);

	printf("%d\n", res);
	return 0;
}
