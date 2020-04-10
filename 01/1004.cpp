#include <stdio.h>

int t;
int x1, y1, x2, y2;
int n, cx, cy, r;
int cnt;

int distance(int a1, int b1, int a2, int b2) {
    return (a1-a2)*(a1-a2) + (b1-b2)*(b1-b2);
}

int main()
{
    for(scanf("%d",&t); t--;)
    {
        cnt = 0;
        
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d %d %d", &cx, &cy, &r);
            
            bool p1 = distance(x1, y1, cx, cy)<r*r;
            bool p2 = distance(x2, y2, cx, cy)<r*r;
            
            cnt += p1^p2;
        }
        
        printf("%d\n", cnt);
    }
}
