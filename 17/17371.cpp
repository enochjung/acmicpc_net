#include <cstdio>
#define N 1000
#define INF 999999999

struct point
{
	int x, y;
};

int n;
point a[N];

int dist(point p, point q)
{
	return (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y);
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d %d", &a[i].x, &a[i].y);

	int min = INF;
	int mini = 0;
	for (int i=0; i<n; ++i)
	{
		int max = 0;
		int maxi = 0;
		for (int j=0; j<n; ++j)
		{
			int d = dist(a[i], a[j]);
			if (max < d)
			{
				max = d;
				maxi = i;
			}
		}
		if (min > max)
		{
			min = max;
			mini = maxi;
		}
	}

	printf("%d %d\n", a[mini].x, a[mini].y);
	return 0;
}