#include <cstdio>
#include <algorithm>
#define N 100010

using namespace std;

int n;
pair<int,int> a[N];

int date(int m, int d)
{
	return m*100+d;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int sm, sd, em, ed;
		scanf("%d %d %d %d", &sm, &sd, &em, &ed);
		a[i].first = date(sm, sd);
		a[i].second = date(em, ed);
	}

	sort(a, a+n);
	a[n] = {date(13,0), 0};

	int res = 0;
	int p=date(1,1), q=date(3,1);
	int last = q;
	for(int i=0; i<=n; ++i)
	{
		if(p<=a[i].first && a[i].first<=q)
			last = max(last, a[i].second);
		else if(q < last)
		{
			--i;
			++res;
			q = last;
			if(q > date(11,30))
				break;
		}
		else
		{
			res = 0;
			break;
		}
	}

	printf("%d", res);
	return 0;
}
