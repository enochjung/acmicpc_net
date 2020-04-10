#include <cstdio>
#include <algorithm>

using namespace std;

int a[3];

int main()
{
	for(int i=0; i<3; ++i)
		scanf("%d", a+i);

	sort(a, a+3);

	if(a[1]-a[0] == a[2]-a[1])
		printf("%d", a[2]+a[2]-a[1]);
	else if(a[1]-a[0] > a[2]-a[1])
		printf("%d", a[0]+a[2]-a[1]);
	else
		printf("%d", a[1]+a[1]-a[0]);

	return 0;
}
