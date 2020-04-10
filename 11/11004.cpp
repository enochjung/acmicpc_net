#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, a[5000010];

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);

	printf("%d", a[k-1]);
	return 0;
}
