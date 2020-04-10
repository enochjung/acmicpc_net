#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a, b;

int main()
{
	a = b = 9999;

	scanf("%d %d", &n, &m);
	while(m--)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		a = min(a, p);
		b = min(b, q);
	}

	printf("%d", min({(n+5)/6*a, n/6*a+n%6*b, n*b}));
	return 0;
}
