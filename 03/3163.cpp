#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

struct ant
{
	int p, w;
	bool operator<(const ant &i) const {
		return p < i.p;
	}
};

int t, n, l, k;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		deque<ant> d;
		deque<int> e;

		scanf("%d %d %d", &n, &l, &k);
		for(int i=0; i<n; i++)
		{
			int p, a;
			scanf("%d %d", &p, &a);
			d.push_back({a>0?l-p:p, a>0?1:-1});
			e.push_back(a);
		}

		sort(d.begin(), d.end());

		int res;
		for(int i=0; i<k; i++)
		{
			if(i+1<n && d[i].p==d[i+1].p && ((d[i].w==1 && e.back()>e.front()) || (d[i].w==-1 && e.front()>e.back())))
				swap(d[i], d[i+1]);

			if(d[i].w == 1)
			{
				res = e.back();
				e.pop_back();
			}
			else
			{
				res = e.front();
				e.pop_front();
			}
		}
		printf("%d\n", res);
	}

	return 0;
}
