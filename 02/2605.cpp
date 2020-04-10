#include <cstdio>
#include <list>

using namespace std;

int n;
list<int> l;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int v;
		scanf("%d", &v);

		auto p = l.begin();
		for(int j=0; j<i-v; j++)
			++p;

		l.insert(p, i+1);
	}

	for(auto p=l.begin(); p!=l.end(); ++p)
		printf("%d ", *p);

	return 0;
}
