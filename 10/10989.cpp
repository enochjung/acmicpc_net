#include <stdio.h>

int n, a[10010];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int v;
        scanf("%d", &v);
        a[v]++;
    }
    
    for (int i=1; i<=10000; i++)
        for (int j=0; j<a[i]; j++)
            printf("%d\n", i);
}
