#include <cstdio>

int n;

bool f()
{
	if(n%400 == 0)
		return true;
	if(n%100 == 0)
		return false;
	if(n%4 == 0)
		return true;
	return false;
}

int main()
{
	scanf("%d", &n);
	printf("%d\n", f());
	return 0;
}
