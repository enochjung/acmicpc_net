#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[60], b[60];
int s;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", a+i);
    for(int i=0; i<n; i++)
        scanf("%d", b+i);
    
    sort(a, a+n);
    sort(b, b+n);
    
    for(int i=0; i<n; i++)
        s += a[i]*b[n-i-1];
    
    printf("%d", s);
}
