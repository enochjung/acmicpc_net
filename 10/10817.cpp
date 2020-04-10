#include <stdio.h>
#include <algorithm>

using namespace std;

int a[3];

int main()
{
    for(int i=0; i<3; i++)
        scanf("%d", a+i);
    sort(a, a+3);
    printf("%d", a[1]);
}
