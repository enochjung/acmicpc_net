#include <stdio.h>
#include <string.h>

int t, k, p[110], n[110];
int d[110][10010];

int f(int idx, int money)
{
    if(idx == k)
        return money==0;
    if(d[idx][money] == -1) {
        d[idx][money] = 0;
        for(int i=0; i<=n[idx] && p[idx]*i<=money; i++)
            d[idx][money] += f(idx+1, money-p[idx]*i);
    }
    return d[idx][money];
}

int main()
{
    memset(d, -1, sizeof(d));
    scanf("%d %d", &t, &k);
    for(int i=0; i<k; i++)
        scanf("%d %d", p+i, n+i);
    
    printf("%d", f(0, t));
}
