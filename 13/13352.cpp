#include <cstdio>
#include <vector>

using namespace std;

struct point
{
	long long x, y;
};

int n;
point p[100010];

bool in_line(point &i, point &j, point &k)
{
	return (i.x-j.x)*(j.y-k.y) == (j.x-k.x)*(i.y-j.y);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%lld %lld", &p[i].x, &p[i].y);
	if(n < 5)
	{
		printf("success");
		return 0;
	}

	// 0 & 1
	{
		vector<point> v;
		for(int i=2; i<n; ++i)
		{
			if(!in_line(p[0], p[1], p[i]))
			{
				if(v.size() < 2)
					v.push_back(p[i]);
				else if(!in_line(v[0], v[1], p[i]))
					break;
			}
			if(i == n-1)
			{
				printf("success");
				return 0;
			}
		}
	}
	
	// 0 & 2
	{
		vector<point> v;
		v.push_back(p[1]);
		for(int i=3; i<n; ++i)
		{
			if(!in_line(p[0], p[2], p[i]))
			{
				if(v.size() < 2)
					v.push_back(p[i]);
				else if(!in_line(v[0], v[1], p[i]))
					break;
			}
			if(i == n-1)
			{
				printf("success");
				return 0;
			}
		}
	}
	
	// 1 & 2
	{
		vector<point> v;
		v.push_back(p[0]);
		for(int i=3; i<n; ++i)
		{
			if(!in_line(p[1], p[2], p[i]))
			{
				if(v.size() < 2)
					v.push_back(p[i]);
				else if(!in_line(v[0], v[1], p[i]))
					break;
			}
			if(i == n-1)
			{
				printf("success");
				return 0;
			}
		}
	}

	printf("failure");
	return 0;
}
