#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 5000

using namespace std;

struct st
{
	long long a[3];
};

int n;
long long v[N];

bool compare(st &a, st b)
{
	if (b.a[0]==b.a[1] || b.a[1]==b.a[2] || b.a[2]==b.a[0])
		return false;
	if (abs(a.a[0]+a.a[1]+a.a[2]) > abs(b.a[0]+b.a[1]+b.a[2]))
		a = b;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%lld", v+i);

	sort(v, v+n);
	
	st res = {v[0], v[n/2], v[n-1]};
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
		{
			long long a = v[i];
			long long b = v[j];
			int idx = (int)(lower_bound(v, v+n, -a-b) - v);
			for (int k=idx; k<n; ++k)
				if (compare(res, {a, b, v[k]}))
					break;
			for (int k=idx-1; k>=0; --k)
				if (compare(res, {a, b, v[k]}))
					break;
		}
	
	sort(res.a, res.a+3);
	printf("%lld %lld %lld\n", res.a[0], res.a[1], res.a[2]);
	return 0;
}