#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[1430];

bool possible()
{
	for(int i=0; i<n-1; i++)
		if(a[i+1]-a[i] > 200)
			return false;
	return a[n-1] >= 1322;
}

int main()
{
	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
			break;
		for(int i=0; i<n; i++)
			scanf("%d", a+i);

		sort(a, a+n);

		printf("%s\n", possible()? "POSSIBLE" : "IMPOSSIBLE");
	}

    return 0;
}
