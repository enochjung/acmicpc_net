#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector<int> v1, v2;

void print(vector<int> &vec)
{
	printf("%d\n", vec.size());
	for (int val : vec)
		printf("%d\n", val);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a < b)
			v1.push_back(i + 1);
		else
			v2.push_back(i + 1);
	}

	print(v1.size() < v2.size() ? v1 : v2);
	return 0;
}