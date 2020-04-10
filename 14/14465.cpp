#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k, b;
int a[100010];
int res;

int main()
{
	scanf("%d %d %d", &n, &k, &b);
	for(int i=0; i<b; i++)
		scanf("%d", a+i);

	b += 2;
	a[b-2] = 0;
	a[b-1] = n+1;

	sort(a, a+b);

	res = 999999;
	for(int i=0,j=1; j<b;)
	{
		if(a[j]-a[i]-1 >= k)
		{
			if(res > j-i-1)
				res = j-i-1;
			i++;
		}
		else
			j++;
	}

	printf("%d\n", res);
	return 0;
}
