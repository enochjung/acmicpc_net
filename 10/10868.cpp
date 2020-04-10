#include <cstdio>
#include <algorithm>
#define N 1<<18
#define INF 1999999999

using namespace std;

int n, m;
int start = N>>1;
int v[N];

void update(int idx, int s, int e, int a, int b, int val)
{
	if(b<=s || e<=a)
		return;

	if(a<=s && e<=b)
	{
		v[idx] = val;
		return;
	}
	
	int mid = (s+e)/2;
	update(idx*2, s, mid, a, b, val);
	update(idx*2+1, mid, e, a, b, val);
	v[idx] = min(v[idx*2], v[idx*2+1]);
}

int get(int idx, int s, int e, int a, int b)
{
	if(b<=s || e<=a)
		return INF;

	if(a<=s && e<=b)
		return v[idx];

	int mid = (s+e)/2;
	return min(get(idx*2, s, mid, a, b), get(idx*2+1, mid, e, a, b));
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		update(1, 0, start, i, i+1, v);
	}

	while(m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", get(1, 0, start, a-1, b));
	}

	return 0;
}
