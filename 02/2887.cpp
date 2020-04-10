#include <cstdio>
#include <algorithm>

using namespace std;

int k, a[31], l;

int main()
{
	for(int i=0; i<31; ++i)
		a[i] = 1<<i;

	scanf("%d", &k);
	for(int i=1; i<31; ++i)
	{
        if (k > a[i])
            k -= a[i];
        else {
            l = i;
            break;
        }
    }
    --k;
    for (int i = l - 1; i >= 0; i--) {
        if (k&a[i])
            printf("7");
        else
            printf("4");
    }
    return 0;
}
