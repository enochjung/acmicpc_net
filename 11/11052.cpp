#include <cstdio>
#include <algorithm>

using namespace std;

int n, p[1010], d[1010];

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", p+i);

	for(int i=0; i<n; i++)
		for(int j=1; j<=n-i; j++)
			d[i+j] = max(d[i+j], d[i]+p[j]);

	printf("%d\n", d[n]);
	return 0;
}
