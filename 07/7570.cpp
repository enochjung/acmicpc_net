#include <stdio.h>

int n, a, d[1000010], k;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        d[a] = d[a-1]+1;
        k = k>d[a]? k : d[a];
    }
    
    printf("%d", n-k);
}
