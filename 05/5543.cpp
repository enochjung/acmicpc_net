#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int a[3], b[3];

	for (int i = 0; i < 3; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < 2; ++i)
		scanf("%d", b + i);

	printf("%d", min({a[0], a[1], a[2]}) + min(b[0], b[1]) - 50);
	return 0;
}