#include <cstdio>
#include <algorithm>

using namespace std;

int t, l, n;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		int a=0, b=0;
		scanf("%d %d", &l, &n);
		while(n--)
		{
			int v;
			scanf("%d", &v);
			a = max(a, min(v,l-v));
			b = max(b, max(v,l-v));
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}
