#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a[500010];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);
	
	sort(a, a+n);

	for(scanf("%d", &m); m--;)
	{
		int v;
		scanf("%d", &v);
		printf("%d ", (int)(upper_bound(a,a+n,v)-lower_bound(a,a+n,v)));
	}

	return 0;
}
