#include <cstdio>
#include <deque>
#define N 1000010

using namespace std;

int n, a, b, c, x[N];
long long s[N], d[N];
deque<int> cht;

long long f(int i, int j)
{
	long long v = s[i]-s[j];
	return v*v*a + v*b + c + d[j];
}

double cross(int i, int j)
{
	return (double)(d[j]-d[i]+(a*s[j]-b)*s[j]-(a*s[i]-b)*s[i])/(2*a*(s[j]-s[i]));
}

int main()
{
	scanf("%d %d %d %d", &n, &a, &b, &c);
	for(int i=0; i<n; ++i)
		scanf("%d", x+i);

	for(int i=0; i<n; ++i)
		s[i+1] = x[i]+s[i];

	cht.push_back(0);
	for(int i=1; i<=n; ++i)
	{
		while(cht.size()>1 && cross(cht[0],cht[1])<s[i])
			cht.pop_front();
		d[i] = f(i, cht[0]);

		int size = (int)cht.size();
		while(size>1 && cross(cht[size-2],i)<=cross(cht[size-2],cht[size-1]))
		{
			cht.pop_back();
			--size;
		}
		cht.push_back(i);
	}

	printf("%lld", d[n]);
	return 0;
}
