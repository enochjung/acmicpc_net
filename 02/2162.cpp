#include <cstdio>
#include <algorithm>
#define N 3000
#define x first
#define y second

using namespace std;

typedef pair<int,int> point;

struct line
{
	point p1, p2;
	void scan()
	{
		scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
	}
};

int n;
line l[N];
int g[N], r[N];

int group(int a)
{
	return a==g[a]? a : g[a]=group(g[a]);
}

void merge(int a, int b)
{
	int ga = group(a);
	int gb = group(b);

	if (ga > gb)
		g[ga] = gb;
	else
		g[gb] = ga;
}

int ccw(point a, point b, point c)
{
	int ret = (a.x*b.y+b.x*c.y+c.x*a.y) - (b.x*a.y+c.x*b.y+a.x*c.y); 
	return ret>0? 1 : (ret<0? -1 : 0);
}

bool cross(line l1, line l2)
{
	int a = ccw(l1.p1, l1.p2, l2.p1);
	int b = ccw(l1.p1, l1.p2, l2.p2);
	int c = ccw(l2.p1, l2.p2, l1.p1);
	int d = ccw(l2.p1, l2.p2, l1.p2);

	if (a==0 && b==0 && c==0 && d==0)
	{
		if (l1.p1 > l1.p2)
			swap(l1.p1, l1.p2);
		if (l2.p1 > l2.p2)
			swap(l2.p1, l2.p2);
		if (l1.p1 > l2.p1)
		{
			swap(l1.p1, l2.p1);
			swap(l1.p2, l2.p2);
		}
		return l1.p2 >= l2.p1;
	}
	return a*b<=0 && c*d<=0;
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		l[i].scan();

	for (int i=0; i<n; ++i)
		g[i] = i;
	
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			if (cross(l[i], l[j]))
				merge(i, j);
	
	for (int i=0; i<n; ++i)
		++r[group(i)];
	
	int res = 0;
	int size = 0;
	for (int i=0; i<n; ++i)
		if (r[i] > 0)
		{
			++res;
			size = max(size, r[i]);
		}
	
	printf("%d\n%d\n", res, size);
	return 0;
}