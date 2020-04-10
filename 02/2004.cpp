#include <cstdio>
#include <cmath>

int n, m;
int t, f;

int main()
{
	scanf("%d %d", &n, &m);

	for(long long i=2; i<=n; i*=2)
		t += floor(1.0*n/i);
	for(long long i=5; i<=n; i*=5)
		f += floor(1.0*n/i);

	for(long long i=2; i<=m; i*=2)
		t -= floor(1.0*m/i);
	for(long long i=5; i<=m; i*=5)
		f -= floor(1.0*m/i);

	for(long long i=2; i<=(n-m); i*=2)
		t -= floor(1.0*(n-m)/i);
	for(long long i=5; i<=(n-m); i*=5)
		f -= floor(1.0*(n-m)/i);

	printf("%d\n", t<f? t : f);
	return 0;
}
