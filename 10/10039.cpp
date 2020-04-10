#include <cstdio>
#include <algorithm>

using namespace std;

int sum;

int main()
{
	for(int i=0; i<5; i++)
	{
		int v;
		scanf("%d", &v);
		sum += max(v, 40);
	}

	printf("%d\n", sum/5);
}
