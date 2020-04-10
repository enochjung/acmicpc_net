#include <stdio.h>

int t, n, m;
long long a;

int main()
{
    for(scanf("%d",&t); t--;) {
        a = 1;
        scanf("%d %d", &n, &m);
        n = (n<m-n? n : m-n);
        for(int i=m; i>m-n; i--)    a *= i;
        for(int i=2; i<=n; i++)     a /= i;
        printf("%lld\n", a);
    }
}
