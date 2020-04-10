#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m;
bool b[10];

int f(int x)
{
	int ret = abs(n-x) + (x==0? 1 : 0);
	while(x)
	{
		++ret;
		x /= 10;
	}
	return ret;
}

bool can_make(int x)
{
	if(x==0 && b[0])
		return false;
	while(x)
	{
		if(b[x%10])
			return false;
		x /= 10;
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	while(m--)
	{
		int v;
		scanf("%d", &v);
		b[v] = true;
	}

	int res = f(100)-3;
	for(int i=n; i>=0; --i)
		if(can_make(i))
			res = min(res, f(i));
	for(int i=n; i<=999999; ++i)
		if(can_make(i))
			res = min(res, f(i));

	printf("%d", res);
	return 0;
}
