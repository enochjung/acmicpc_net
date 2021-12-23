#include <cstdio>
#include <algorithm>
#define N 9

int main()
{
	int max=0, idx=0;

	for (int i=0; i<N; ++i)
	{
		int val;
		scanf("%d", &val);

		if (max < val)
		{
			max = val;
			idx = i;
		}
	}

	printf("%d\n%d\n", max, idx+1);
    return 0;
}