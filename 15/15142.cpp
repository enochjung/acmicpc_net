#include <cstdio>
#include <vector>

using namespace std;

struct st
{
	int s;
	long long v;
	int t;
};

long long n;

bool check(long long v, int s)
{
	long long vv = 1;

	while(s--)
	{
		if(vv*v/v != vv)
			return false;
		vv *= v;
	}

	return vv <= n;
}

long long get(int s)
{
	long long low=1, high=n, res=0;

	while(low <= high)
	{
		long long mid = (low+high)/2;

		if(check(mid, s))
		{
			res = mid;
			low = mid+1;
		}
		else
			high = mid-1;
	}

	return res;
}

int main()
{
	scanf("%lld", &n);

	if((n&(n-1)) == 0)
	{
		printf("-1");
		return 0;
	}

	vector<st> res;
	for(int i=1; i<=60; ++i)
	{
		long long v = get(i);
		long long vv = 1;

		for(int k=0; k<i; ++k)
			vv *= v;
		for(int k=0; k<i; ++k)
		{
			if(vv == n)
			{
				res.push_back({i, v, k});
				break;
			}
			vv /= v;
			vv *= (v+1);
		}
	}

	printf("%d", (int)res.size());
	for(st &v : res)
	{
		printf("\n%d", v.s);
		for(int i=0; i<v.s-v.t; ++i)
			printf(" %lld", v.v);
		for(int i=0; i<v.t; ++i)
			printf(" %lld", v.v+1);
	}

	return 0;
}
