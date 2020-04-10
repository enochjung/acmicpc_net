#include <cstdio>
#include <algorithm>

using namespace std;

int a[7];
int res;

int main()
{
	for(int i=1; i<7; i++)
		scanf("%d", a+i);

	res = a[6]+a[5]+a[4]+(a[3]+3)/4;
	a[1] = max(a[1]-a[5]*11, 0);
	a[1] = max(a[1]-max(a[4]*5-a[2],0)*4, 0);
	a[2] = max(a[2]-a[4]*5, 0);
	if(a[3]%4)
	{
		a[1] = max(a[1]-max(5-a[2],0)*4-8+a[3]%4, 0);
		a[2] = max(a[2]-7+a[3]%4*2, 0);
	}
	if(a[2]%9)
		a[1] = max(a[1]-(9-a[2]%9)*4, 0);
	res += (a[2]+8)/9+(a[1]+35)/36;

	printf("%d", res);
	return 0;
}
