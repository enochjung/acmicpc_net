#include <cstdio>
#include <set>

using namespace std;

int n, m;
int a[100010];

int main()
{
	scanf("%d %d", &n, &m);

	while(m--)
	{
		int t, i, x;
		scanf("%d", &t);
		
		if(t == 1)
		{
			scanf("%d %d", &i, &x);
			a[i] |= 1<<(x-1);
		}
		else if(t == 2)
		{
			scanf("%d %d", &i, &x);
			a[i] ^= a[i]&(1<<(x-1));
		}
		else if(t == 3)
		{
			scanf("%d", &i);
			a[i] <<= 1;
			a[i] ^= a[i]&(1<<20);
		}
		else
		{
			scanf("%d", &i);
			a[i] >>= 1;
		}
	}

	int res = 0;
	set<int> s;
	for(int i=1; i<=n; ++i)
		if(s.find(a[i]) == s.end())
		{
			s.insert(a[i]);
			++res;
		}
	printf("%d", res);

	return 0;
}
