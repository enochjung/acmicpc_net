#include <cstdio>
#include <algorithm>
#include <vector>
#define N 10
#define R 42

std::vector<int> v;

int main()
{
	for (int i=0; i<N; ++i)
	{
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}

	std::transform(v.begin(), v.end(), v.begin(), [](int x) { return x%R; });
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());

	printf("%d\n", (int)v.size());
	return 0;
}