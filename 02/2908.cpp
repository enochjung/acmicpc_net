#include <cstdio>
#include <algorithm>

using namespace std;

int a, b;

int f(int x)
{
	return x%10*100 + x/10%10*10 + x/100;
}

int main()
{
	scanf("%d %d", &a, &b);
	printf("%d\n", max(f(a),f(b)));
	return 0;
}
