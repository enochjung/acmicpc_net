#include <cstdio>
#include <set>
#define N 110

using namespace std;

int n, k, a[N];
set<int> s;

int pos(int x, int idx)
{
	for(int i=idx; i<k; ++i)
		if(a[i] == x)
			return i;
	return k;
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<k; ++i)
		scanf("%d", a+i);

	int res = 0;
	for(int i=0; i<k; ++i)
	{
		if(s.find(a[i]) != s.end())
			continue;

		if((int)s.size() == n)
		{
			int mv, mp=0;
			for(int v : s)
			{
				int idx = pos(v, i+1);
				if(mp < idx)
				{
					mv = v;
					mp = idx;
				}
			}
			s.erase(mv);
			++res;
		}
		s.insert(a[i]);
	}

	printf("%d", res);
	return 0;
}
