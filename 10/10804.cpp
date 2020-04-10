#include <stdio.h>
#include <algorithm>

using namespace std;

int d[30];

int main()
{
	for(int i=1; i<=20; i++)
		d[i] = i;

	for(int t=0; t<10; t++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		for(int i=0; i<(b-a+1)/2; i++)
			swap(d[a+i], d[b-i]);
	}

	for(int i=1; i<=20; i++)
		printf("%d ", d[i]);

	return 0;
}
