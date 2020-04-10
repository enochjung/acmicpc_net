#include <stdio.h>

int n, x;

int main()
{
    scanf("%d %d", &n, &x);
    while(n--) {
        int v;
        scanf("%d", &v);
        if(x>v) printf("%d ", v);
    }
}
