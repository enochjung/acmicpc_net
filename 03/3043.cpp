#include <cstdio>
#include <algorithm>
#include <vector>
#define N 510

using namespace std;

struct st
{
	int i, v;
	bool operator<(const st &hs) const
	{
		return v<hs.v;
	}
};

int n;
st x[N], y[N];
char p[] = "ULDR";
vector<st> res;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		x[i] = {i, a};
		y[i] = {i, b};
	}

	sort(x, x+n);
	sort(y, y+n);
	for(int i=0; i<n; ++i)
		for(; x[i].v>i+1; --x[i].v)
			res.push_back({x[i].i, 0});
	for(int i=n-1; i>=0; --i)
		for(; x[i].v<i+1; ++x[i].v)
			res.push_back({x[i].i, 2});
	for(int i=0; i<n; ++i)
	{
		for(; y[i].v>i+1; --y[i].v)
			res.push_back({y[i].i, 1});
		for(; y[i].v<i+1; ++y[i].v)
			res.push_back({y[i].i, 3});
	}

	printf("%d\n", (int)res.size());
	for(st &s : res)
		printf("%d %c\n", s.i+1, p[s.v]);
	return 0;
}
