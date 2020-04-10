#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define N 200010

using namespace std;

struct st
{
	int h, v;
	bool operator<(const st &i) const
	{
		return h!=i.h? h<i.h : v>i.v;
	}
};

int z, n, a[N];
int d[N][2];
set<st> s;

void insert(int idx)
{
	auto it = s.insert({a[idx], d[idx][0]}).first;

	if(it != s.begin())
	{
		if((--it)->v >= d[idx][0])
		{
			s.erase(++it);
			return;
		}
		else
			++it;
	}

	while(++it!=s.end() && d[idx][0]>=it->v)
		s.erase(it--);
}

int get(int h)
{
	auto it = s.lower_bound({h, 999999});
	return it!=s.begin()? (--it)->v : 0;
}

int main()
{
	for(scanf("%d",&z); z--;)
	{
		memset(d, 0, sizeof(d));
		d[0][0] = d[0][1] = 1;

		scanf("%d", &n);
		for(int i=0; i<n; ++i)
			scanf("%d", a+i);

		int res = 1;
		insert(0);
		for(int i=1; i<n; ++i)
		{
			d[i][0] = a[i-1]<a[i]? d[i-1][0]+1 : 1;
			d[i][1] = max({d[i][0], a[i-1]<a[i]? d[i-1][1]+1 : 0, get(a[i])+1});
			insert(i);
			res = max(res, d[i][1]);
		}
		
		printf("%d\n", res);
		s.clear();
	}

	return 0;
}
