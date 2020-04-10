#include <cstdio>
#include <algorithm>

using namespace std;

double a, b, c;

int main()
{
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("%d", (int)max(a*b/c, a/b*c));
	return 0;
}
