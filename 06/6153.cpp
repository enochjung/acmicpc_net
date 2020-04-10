#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 1000010
#define Q 25010
#define ST (1<<20)

using namespace std;

struct st
{
	int l, r, a;
	bool operator<(const st &hs) const
	{
		return a > hs.a;
	}
};

int n, q;
st a[Q];
bool t[ST*2];

bool update(int idx, int s, int e, int a, int b)
{
	if(t[idx] || b<s || e<a)
		return t[idx];
	if(a<=s && e<=b)
		return t[idx] = true;

	int mid = (s+e)/2;
	bool left = update(idx*2, s, mid, a, b);
	bool right = update(idx*2+1, mid+1, e, a, b);
	return t[idx] = left&right;
}

int get(int idx, int s, int e, int a, int b)
{
	if(b<s || e<a)
		return -1;
	if(a<=s && e<=b)
		return t[idx];
	if(t[idx])
		return 1;

	int mid = (s+e)/2;
	int left = get(idx*2, s, mid, a, b);
	int right = get(idx*2+1, mid+1, e, a, b);

	if(left == -1)
		return right;
	if(right == -1)
		return left;
	return left&right;
}

bool f(int x)
{
	memset(t, 0, sizeof(t));

	vector<st> v;
	v.assign(a, a+x);
	sort(v.begin(), v.end());

	int bl=n, br=1, sl=1, sr=n;
	for(int i=0; i<(int)v.size(); ++i)
	{
		bl = min(bl, v[i].l);
		br = max(br, v[i].r);
		sl = max(sl, v[i].l);
		sr = min(sr, v[i].r);

		if(i==(int)v.size()-1 || v[i].a!=v[i+1].a)
		{
			if(sl>sr || get(1,1,n,sl,sr))
				return true;
			update(1, 1, n, bl, br);
			bl=n, br=1, sl=1, sr=n;
		}
	}

	return false;
}

int main()
{
	scanf("%d %d", &n, &q);
	for(int i=0; i<q; ++i)
		scanf("%d %d %d", &a[i].l, &a[i].r, &a[i].a);

	int lo=1, hi=q;
	int res = 0;
	while(lo <= hi)
	{
		int mid = (lo+hi)/2;

		if(f(mid))
		{
			res = mid;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}

	printf("%d", res);
	return 0;
}
