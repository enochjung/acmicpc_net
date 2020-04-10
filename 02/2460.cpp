#include <cstdio>
#include <algorithm>

using namespace std;

int res;

int main()
{
	int cnt = 0;
	for(int i=0; i<10; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		cnt += b-a;
		res = max(res, cnt);
	}
	printf("%d\n", res);
}
