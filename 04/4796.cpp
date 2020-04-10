#include <cstdio>
#include <algorithm>

using namespace std;

int l, p, v;

int main()
{
	for(int i=1; scanf("%d %d %d",&l,&p,&v), l>0; ++i)
		printf("Case %d: %d\n", i, v/p*l + min(v%p,l));
	return 0;
}
