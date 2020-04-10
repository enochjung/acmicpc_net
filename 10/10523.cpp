#include <cstdio>
#include <random>

using namespace std;

struct point
{
	long long x, y;
};

int n, p;
point d[100010];

bool in_line(point &i, point &j, point &k)
{
	return (i.x-j.x)*(j.y-k.y) == (j.x-k.x)*(i.y-j.y);
}

bool possible(int value)
{
	static random_device rd;  
	static mt19937 gen(rd());
	static uniform_int_distribution<> dist(0,n-1);

	int a, b, cnt=0;
	do
	{
		a = dist(gen);
		b = dist(gen);
	} while(a == b);

	for(int i=0; i<n; ++i)
	{
		if(in_line(d[a], d[b], d[i]))
			++cnt;
		if(cnt >= value)
			return true;
	}
	return false;
}

int main()
{
	scanf("%d %d", &n, &p);
	for(int i=0; i<n; ++i)
		scanf("%lld %lld", &d[i].x, &d[i].y);
	if(n <= 2)
	{
		printf("possible");
		return 0;
	}

	for(int t=0; t<150; ++t)
		if(possible((n*p+99)/100))
		{
			printf("possible");
			return 0;
		}
	printf("impossible");
	return 0;
}
