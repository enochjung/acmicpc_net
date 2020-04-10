#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#define N 50010

using namespace std;

struct st
{
	int w, h;
	
	bool operator<(const st &hs) const
	{
		return w!=hs.w? w>hs.w : h>hs.h;
	}
	bool operator==(const st &hs) const
	{
		return w>=hs.w && h>=hs.h;
	}
};

int n;
long long d[N];
deque<int> c;
vector<st> v;

long long f(int i, int j)
{
	return 1LL*v[j].w*v[i-1].h+d[j];
}

bool g(int i, int j, int k)
{
	return (d[i]-d[j])*(v[i].w-v[k].w) <= (d[i]-d[k])*(v[i].w-v[j].w);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int w, h;
		scanf("%d %d", &w, &h);
		v.push_back({w, h});
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()), v.end());
	n = (int)v.size();

	c.push_back(0);
	for(int i=1; i<=n; ++i)
	{
		while(c.size()>1 && f(i,c[0])>=f(i,c[1]))
			c.pop_front();
		d[i] = f(i,c[0]);

		while(c.size()>1 && g(c[c.size()-2], c.back(), i))
			c.pop_back();
		c.push_back(i);
	}
	printf("%lld", d[n]);
	return 0;
}
