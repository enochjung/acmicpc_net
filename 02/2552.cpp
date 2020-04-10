#include <cstdio>
#include <map>

using namespace std;

int n, a[40], k;
map<pair<int,int>,int> d;

bool turnable(int x, int idx)
{
	return (x&(1<<idx)) == 0;
}

int update(int x, int idx)
{
	for(int i=idx-1; i>=0; --i)
		if(a[n-1-i] < a[n-1-idx])
			x |= 1<<i;
	return x;
}

int f(int x, int idx)
{
	x %= 1<<idx;
	if(idx == 0)
		return 1;
	pair<int,int> t = {x, idx};
	if(d.find(t) == d.end())
	{
		d[t] = f(x, idx-1);
		if(turnable(x, idx-1))
			d[t] += f(update(x,idx-1), idx-1);
	}

	return d[t];
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);
	scanf("%d", &k);

	int res=0, check=0;
	for(int i=n-1,b=1<<(n-1); b>0; --i,b>>=1)
		if(turnable(check,i) && f(check,i)<k)
		{
			k -= f(check, i);
			check = update(check, i);
			res |= b;
		}

	printf("%d", k!=1? -1 : res);
	return 0;
}
