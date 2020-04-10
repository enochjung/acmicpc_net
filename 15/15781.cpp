#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a, b;

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		a = max(a, v);
	}
	for(int i=0; i<m; ++i)
	{
		int v;
		scanf("%d", &v);
		b = max(b, v);
	}

	printf("%d", a+b);
	return 0;
}
