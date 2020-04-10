#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, a[100010], v;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", a+i);
    sort(a, a+n);
    
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &v);
        printf("%d\n", binary_search(a, a+n, v));
    }
}
