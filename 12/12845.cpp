#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, s;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		m = max(m, v);
		s += v;
	}
	printf("%d", m*(n-2)+s);
	return 0;
}
