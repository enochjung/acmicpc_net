#include <stdio.h>

int n, k;
int d[50]={1,1}, t[50]={0,1}, res;

int main()
{
    scanf("%d %d", &n, &k);
    for(int i=2; i<=n; i++) {
        d[i] = d[i-1]+d[i-2];
        t[i] = d[i-1]+t[i-1];
    }
    res = d[k-1]*d[n-k];
    
    for(int i=1; i<k; i++) {
        res += t[i]*d[k-i-1]*d[n-k];
        res += t[k-i]*d[i-1]*d[n-k];
        res -= d[i-1]*d[k-i-1]*d[n-k];
    }
    for(int i=k+1; i<=n; i++) {
        res += t[i-k]*d[n-i]*d[k-1];
        res += t[n-i+1]*d[i-k-1]*d[k-1];
        res -= d[n-i]*d[i-k-1]*d[k-1];
    }
    
    printf("%d", res);
}
