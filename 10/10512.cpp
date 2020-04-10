#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 150010
#define ST (1<<18)

using namespace std;

int n, k;
int m[ST*2];

struct box
{
	int v, c;
	bool operator<(const box &i) const
	{
		return v-c < i.v-i.c;
	}
} b[N];

bool compare(int i, struct box &j)
{
	return i < j.v-j.c;
}

void update(int idx, int val)
{
	int p = idx+ST;

	m[p] = val;
	while(p > 1)
	{
		p /= 2;
		m[p] = min(m[p*2], m[p*2+1]);
	}
}

int get(int idx, int s, int e, int a, int b)
{
	if(a<=s && e<=b)
		return m[idx];
	if(b<=s || e<=a)
		return 0x7f7f7f7f;

	int mid = (s+e)/2;
	int ret1 = get(idx*2, s, mid, a, b);
	int ret2 = get(idx*2+1, mid, e, a, b);
	
	return min(ret1, ret2);
}

// not black malangcow
//
// after k process, no item left such that Vi-Ci > x
int f(int x)
{
	printf("f(%d) start\n", x);
	for (int w = 0; w < k; ++w)
	{
		int idx = (upper_bound(b, b + n, x, compare) - b);
		printf("idx:%d\n", idx);
		if (idx >= n)
			break;
		x += get(1, 0, ST, idx, n);
		printf("get(1, 0, ST, %d, %d) : %d\n", idx, n, get(1, 0, ST, idx, n));
		printf("w:%d, x:%d\n", w, x);
	}

	printf("%d, %d\n", x, b[n - 1].v - b[n - 1].c);
	return x <= b[n - 1].v - b[n - 1].c;
}

int main()
{
	int t;
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d", &n, &k);
		for(int i=0; i<n; ++i)
			scanf("%d %d", &b[i].v, &b[i].c);

		memset(m, 0x7F, sizeof(m));
		sort(b, b+n);

		for(int i=0; i<n; ++i)
			update(i, b[i].c);

		int res = 0;
		int low = 0;
		int high = b[n-1].v-b[n-1].c;
		while(low <= high)
		{
			int mid = (low+high)/2;

			if(f(mid))
			{
				res = mid;
				high = mid-1;
			}
			else
				low = mid+1;
		}

		printf("%d\n", res);   
	}
	return 0;
}
