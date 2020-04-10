#include <cstdio>
#include <algorithm>

using namespace std;

int a[5], sum;

int main()
{
	for(int i=0; i<5; i++)
	{
		scanf("%d", a+i);
		sum += a[i];
	}

	sort(a, a+5);

	printf("%d\n%d", sum/5, a[2]);
	return 0;
}
