#include <cstdio>
#include <algorithm>

using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	n /= 364;

	int k = max(1, (n-98)/3);
	printf("%d\n%d", n-k*3, k);
	return 0;
}
