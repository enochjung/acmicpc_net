#include <cstdio>
#include <algorithm>

using namespace std;

int a[10];
int sum, p, q;

int main()
{
	for(int i=0; i<9; i++)
	{
		scanf("%d", a+i);
		sum += a[i];
	}

	sort(a, a+9);

	for(int i=0; i<9; i++)
		for(int j=i+1; j<9; j++)
			if(a[i]+a[j]+100 == sum)
				p=i, q=j;

	for(int i=0; i<9; i++)
		if(i!=p && i!=q)
			printf("%d\n", a[i]);

	return 0;
}
