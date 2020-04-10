#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

int n, a[110];
set<int> s;

int gcd(int p, int q)
{
	return p%q? gcd(q,p%q) : q;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	int v = abs(a[1]-a[0]);
	for(int i=0; i<n-1; ++i)
		for(int j=i+1; j<n; ++j)
			v = gcd(v, abs(a[i]-a[j]));

	for(int i=1; i*i<=v; ++i)
		if(v%i == 0)
		{
			s.insert(i);
			s.insert(v/i);
		}
	s.erase(1);

	for(int v : s)
		printf("%d ", v);
	return 0;
}
