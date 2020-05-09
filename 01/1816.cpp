#include <cstdio>

int n;

bool isAcceptable(long long value)
{
	for (int i = 2; i <= 1000000; ++i)
		if (value % i == 0)
			return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		long long value;
		scanf("%lld", &value);
		printf("%s\n", isAcceptable(value) ? "YES" : "NO");
	}
	return 0;
}