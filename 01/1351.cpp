#include <cstdio>
#include <map>

using namespace std;

long long n;
int p, q;
map<long long,long long> m;

long long f(long long x)
{
	if(x == 0)
		return 1;
	if(m[x] != 0)
		return m[x];
	return m[x] = f(x/p)+f(x/q);
}

int main()
{
	scanf("%lld %d %d", &n, &p, &q);
	printf("%lld", f(n));
	return 0;
}
