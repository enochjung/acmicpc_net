#include <stdio.h>
#include <algorithm>

using namespace std;

int n, h, d[210], k;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        cin >> h;
        int idx = (int)(lower_bound(d, d+k, h)-d);
        d[idx] = h;
        if(idx == k) k++;
    }

    printf("%d", n-k);
}
