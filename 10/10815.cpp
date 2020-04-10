#include <cstdio>
#include <algorithm>
#define N 500010

using namespace std;

int n, m, a[N];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);

	scanf("%d", &m);
	while(m--)
	{
		int v;
		scanf("%d", &v);
		printf("%d ", binary_search(a, a+n, v));
	}

	return 0;
}
