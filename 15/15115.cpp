#include <cstdio>
#include <algorithm>

using namespace std;

int k, p, x;

int main()
{
	scanf("%d %d %d", &k, &p, &x);

	double res = 9999999;
	for(int i=1; i<=10000; ++i)
		res = min(res, 1.0*k*p/i + 1.0*x*i);
	printf("%.3lf", res);
	return 0;
}
