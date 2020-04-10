#include <cstdio>
#include <set>
#define K 110

using namespace std;

int k, n, a[K];
set<int> s;

int main()
{
	scanf("%d %d", &k, &n);
	for(int i=0; i<k; ++i)
		scanf("%d", a+i);

	int lim = 0x7f;
	s.insert(1);
	while(n--)
	{
		if((int)s.size() > n+10)
		{
			auto it = s.end();
			--it;
			lim = *it;
		}
		int v = *(s.begin());
		s.erase(s.begin());

		for(int i=0; i<k; ++i)
			if(v*a[i] < lim)
				s.insert(v*a[i]);
	}
	printf("%d", *(s.begin()));
	return 0;
}
