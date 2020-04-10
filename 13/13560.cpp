#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[10010], rem;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);

	sort(a, a+n);

	for(int i=n-1; i>=0; i--)
	{
		if(a[i] > i+rem)
		{
			printf("-1\n");
			return 0;
		}
		rem += i-a[i];
	}

	printf("%d", rem? -1 : 1);
	return 0;
}
