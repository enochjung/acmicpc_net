#include <cstdio>
#include <list>

using namespace std;

int n, s;

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		list<int> l;

		for(int i=0; i<n; ++i)
		{
			int v;
			scanf("%d", &v);
			l.push_back(v);
		}
		scanf("%d", &s);

		while(!l.empty())
		{
			int mi = 0;
			list<int>::iterator t=l.begin(), it=l.begin();

			for(int c=1; c<=s && c<(int)l.size(); ++c)
			{
				++it;
				if(*t < *it)
				{
					t = it;
					mi = c;
				}
			}

			printf("%d ", *t);
			s -= mi;
			l.erase(t);
		}
		printf("\n");
	}

	return 0;
}
