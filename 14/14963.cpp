#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[12]={0,0,4,4,4,4,4,4,4,4,16,4};

int main()
{
	scanf("%d", &n);

	int sum = 0;
	while(n--)
	{
		int v;
		scanf("%d", &v);
		sum += v;
		--a[v];
	}

	int x = 21-sum;
	int alive=0, dead=0;
	for(int i=2; i<=x; ++i)
		alive += a[i];
	for(int i=max(x+1,2); i<=11; ++i)
		dead += a[i];

	printf("%s", alive>dead? "VUCI" : "DOSTA");
	return 0;
}
