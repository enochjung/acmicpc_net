#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010

using namespace std;

int n;

struct st
{
	char a[11];
	int k, e, m;

	void scan()
	{
		scanf(" %s %d %d %d", a, &k, &e, &m);
	}
	bool operator<(const st &hs) const
	{
		return k!=hs.k? k>hs.k : e!=hs.e? e<hs.e : m!=hs.m? m>hs.m : strcmp(a, hs.a)<0;
	}
} a[N];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		a[i].scan();

	sort(a, a+n);

	for(int i=0; i<n; ++i)
		printf("%s\n", a[i].a);
	return 0;
}
