#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct st
{
	int y, x1, x2, v;
	bool operator<(const st &hs) const
	{
		return y < hs.y;
	}
};

struct point
{
	int x, y;
};

int t, n, k;
int s[1000010], size;

void update(int idx, int val)
{
	while(idx)
	{
		s[idx] += val;
		idx -= idx&-idx;
	}
}

int get(int idx)
{
	int sum = 0;
	while(idx <= size)
	{
		sum += s[idx];
		idx += idx&-idx;
	}
	return sum;
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		map<int,int> xtoi;
		set<int> x;
		vector<st> h;

		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			point p[110];

			scanf("%d", &k);
			for(int j=0; j<k; ++j)
				scanf("%d %d", &p[i].x, &p[i].y);

			p[k] = p[0];
			for(int j=0; j<k; ++j)
			{
				x.insert(p[j].x);
				if(p[j].x < p[j+1].x)
					h.push_back({p[j].y, p[j].x, p[j+1].x, 1});
				else if(p[j].x > p[j+1].x)
					h.push_back({p[j].y, p[j+1].x, p[j].x, -1});
			}
		}

		sort(h.begin(), h.end());

		size = 0;
		for(int v : x)
			xtoi[v] = ++size;
		memset(s, -1, sizeof(s));

		int res = 0;
		for(auto v : h)
		{
			update(v.x2, v.v);
			update(v.x1, -v.v);
			res = max(res, get(v.x2));
		}
		printf("%d\n", res);
	}
	
	return 0;
}
