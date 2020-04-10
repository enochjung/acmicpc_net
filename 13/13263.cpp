#include <cstdio>
#include <deque>
#define N 100010

using namespace std;

int n, a[N], b[N];
long long d[N];
deque<int> c;

long long f(int i, int j)
{
	return 1LL*b[j]*a[i]+d[j];
}

bool g(int i, int j, int k)
{
	return (double)(d[i]-d[j])/(b[i]-b[j]) <= (double)(d[i]-d[k])/(b[i]-b[k]);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);
	for(int i=0; i<n; ++i)
		scanf("%d", b+i);

	c.push_back(0);
	for(int i=1; i<n; ++i)
	{
		while(c.size()>1 && f(i,c[0])>=f(i,c[1]))
			c.pop_front();
		d[i] = f(i,c[0]);

		while(c.size()>1 && g(c[c.size()-2], c.back(), i))
			c.pop_back();
		c.push_back(i);
	}
	printf("%lld", d[n-1]);
	return 0;
}
