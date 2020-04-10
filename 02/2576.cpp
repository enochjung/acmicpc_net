#include <cstdio>
#include <algorithm>

using namespace std;

int a, b=99;

int main()
{
	for(int i=0; i<7; ++i)
	{
		int v;
		scanf("%d", &v);
		if(v&1)
		{
			a += v;
			b = min(b, v);
		}
	}

	if(a)
		printf("%d\n%d", a, b);
	else
		printf("-1");
	return 0;
}
