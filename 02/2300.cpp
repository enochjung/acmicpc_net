#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define N 10010
#define INF 9999999

using namespace std;

struct st {
    int x, y;
    bool operator<(const st &i) const {
        return x<i.x;
    }
} a[N];

int n, d[N];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d %d", &a[i].x, &a[i].y);
    
    sort(a, a+n);
    
    for(int i=0; i<n; i++) {
        int m = 0;
        d[i] = INF;
        for(int j=i; j>=0; j--) {
            m = max(m, a[i].x-a[j].x);
            m = max(m, abs(a[j].y)*2);
            d[i] = min(d[i], (j==0?0:d[j-1])+m);
        }
    }
    
    printf("%d", d[n-1]);
}
