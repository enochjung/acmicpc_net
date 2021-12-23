#include <cstdio>
#include <algorithm>

using namespace std;

int r, c;

int main()
{
	int rm = -1, cm = -1;

	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; ++i)
	{
		int v;
		scanf("%d", &v);
		rm = max(rm, v);
	}
	for (int i = 0; i < c; ++i)
	{
		int v;
		scanf("%d", &v);
		cm = max(cm, v);
	}

	printf("%s\n", rm == cm ? "possible" : "impossible");
	return 0;
}