#include <stdio.h>
#include <map>

using namespace std;

int n, s, m;
map<int, bool> d[2];

int main()
{
	scanf("%d %d %d", &n, &s, &m);

	d[1-n&1][s] = true;
	while(n--)
	{
		int v;
		scanf("%d", &v);

		d[1-n&1].clear();
		for(auto i=d[n&1].begin(); i!=d[n&1].end(); ++i)
		{
			if(0 <= i->first-v)
				d[1-n&1][i->first-v] = true;
			if(i->first+v <= m)
				d[1-n&1][i->first+v] = true;
		}
	}

	if(d[1].empty())
		printf("-1");
	else
	{
		auto i = d[1].end();
		printf("%d", (--i)->first);
	}

	return 0;
}
