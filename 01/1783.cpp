#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int res;

int main()
{
	scanf("%d %d", &n, &m);
	
	if(n == 1)
		res = 1;
	else if(n == 2)
		res = min((m+1)/2, 4);
	else
		res = max(m-2, min(m,4));

	printf("%d", res);
	return 0;
}
