#include <cstdio>
#include <algorithm>
#include <vector>
#define NB (1<<18)

using namespace std;

int n, m;
vector<int> t[NB*2];

void build(int x)
{
	if(x >= NB)
		return;
	build(x*2);
	build(x*2+1);
	t[x].assign(t[x*2].size()+t[x*2+1].size(), 0);
	merge(t[x*2].begin(),t[x*2].end(),t[x*2+1].begin(),t[x*2+1].end(),t[x].begin());
}

int get(int x, int s, int e, int a, int b, int c)
{
	if(e<a || b<s)
		return 0;
	if(a<=s && e<=b)
		return (int)(t[x].end()-upper_bound(t[x].begin(),t[x].end(),c));

	int mid = (s+e)/2;
	return get(x*2,s,mid,a,b,c)+get(x*2+1,mid+1,e,a,b,c);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		t[NB+i].push_back(v);
	}
	build(1);

	scanf("%d", &m);
	int res = 0;
	while(m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a ^= res;
		b ^= res;
		c ^= res;
		res = get(1, 1, NB, a, b, c);
		printf("%d\n", res);
	}

	return 0;
}
