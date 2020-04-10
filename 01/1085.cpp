#include <cstdio>
#include <algorithm>

using namespace std;

int x, y, w, h;

int main()
{
	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d\n", min(x, min(y, min(w-x, h-y))));
	return 0;
}
