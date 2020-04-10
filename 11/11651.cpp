#include <stdio.h>
#include <algorithm>

using namespace std;

struct st {
    int x, y;
    bool operator<(const st &i) const {
        return (y==i.y)? x<i.x : y<i.y;
    }
} a[100010];

int n;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d %d", &a[i].x, &a[i].y);
    
    sort(a, a+n);
    
    for(int i=0; i<n; i++)
        printf("%d %d\n", a[i].x, a[i].y);
}
