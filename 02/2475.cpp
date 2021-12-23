#include <cstdio>
#define N 5

int main()
{
	int sum = 0;
	for (int i=0; i<N; ++i)
	{
		int val;
		scanf("%d", &val);
		sum += val*val;
	}
	printf("%d\n", sum % 10);
    return 0;
}