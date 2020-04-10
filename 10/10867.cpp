#include <cstdio>
#include <set>

using namespace std;

int n;
set<int> s;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int v;
		scanf("%d", &v);
		s.insert(v);
	}

	for(auto it=s.begin(); it!=s.end(); ++it)
		printf("%d ", *it);
	return 0;
}
