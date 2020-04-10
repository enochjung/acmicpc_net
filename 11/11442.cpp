#include <cstdio>
#include <vector>
#define R 1000000007

using namespace std;

long long n;

void m(vector<int> &s, vector<int> t)
{
	long long a, b, c, d;
	a = 1LL*s[0]*t[0] + 1LL*s[1]*t[2];
	b = 1LL*s[0]*t[1] + 1LL*s[1]*t[3];
	c = 1LL*s[2]*t[0] + 1LL*s[3]*t[2];
	d = 1LL*s[2]*t[1] + 1LL*s[3]*t[3];
	s = {(int)(a%R), (int)(b%R), (int)(c%R), (int)(d%R)};
}

vector<int> f(long long x)
{
	vector<int> res({1, 1, 1, 0});

	if(x == 0)
		res = {0, 0, 0, 0};
	else if(x > 1)
	{
		vector<int> v = f(x/2);
		m(v, v);

		if(x & 1)
			m(res, v);
		else
			res = v;
	}

	return res;
}

int main()
{
	scanf("%lld", &n);
	printf("%d\n", f((n+1)/2*2)[1]);
	return 0;
}
