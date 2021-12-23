#include <stdio.h>
#include <algorithm>

using namespace std;

struct point
{
	int x, y;
} p[60];

int t, n;

bool compare(const point &i, const point &j)
{
	int dix=i.x-p[0].x, diy=i.y-p[0].y;
	int djx=j.x-p[0].x, djy=j.y-p[0].y;
	return 1LL*diy*diy*(djx*djx+djy*djy) < 1LL*djy*djy*(dix*dix+diy*diy);
}

int main()
{
	for (scanf("%d",&t); t--;)
	{
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			p[i] = {x, y};
			if(p[0].y>p[i].y || (p[0].y==p[i].y && p[0].x>p[i].x))
				swap(p[0], p[i]);
		}

		sort(p+1, p+n, [](point));

		for(int i=0; i<n; i++)
			printf("%d %d\n", p[i].x, p[i].y);
	}

	return 0;
}
