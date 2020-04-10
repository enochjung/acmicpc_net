#include <stdio.h>

int n, a;
int sum, max=-9999;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        sum += a;
        if(max<sum) max=sum;
        if(sum<0) sum=0;
    }
    printf("%d", max);
}
