#include <cstdio>
#include <vector>

using namespace std;

int t, p, q;

vector<int> m(vector<int> &s, vector<int> &e)
{
	long long a, b, c, d;
	a = 1LL*s[0]*e[0] + 1LL*s[1]*e[2];
	b = 1LL*s[0]*e[1] + 1LL*s[1]*e[3];
	c = 1LL*s[2]*e[0] + 1LL*s[3]*e[2];
	d = 1LL*s[2]*e[1] + 1LL*s[3]*e[3];
	return {(int)(a%q), (int)(b%q), (int)(c%q), (int)(d%q)};
}

vector<int> f(int x)
{
	vector<int> res({1, 1, 1, 0});

	if(x > 1)
	{
		vector<int> v = f(x/2);
		v = m(v, v);
		res = x&1? m(res,v) : v;
	}

	return res;
}

int main()
{
	scanf("%d", &t);
	for(int i=1; i<=t; i++)
	{
		scanf("%d %d", &p, &q);
		printf("Case #%d: %d\n", i, f(p-1)[0]);
	}
	return 0;
}
