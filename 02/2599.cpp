#include <stdio.h>

int n, a[6], b[6];

int min(int i,int j){return i<j?i:j;}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<6; i++)
        scanf("%d", a+i);
    
    for(b[0]=0; b[0]<=min(a[0],a[3]); b[0]++) {
        b[1] = a[0]-b[0];
        b[3] = a[5]-b[1];
        b[2] = a[2]-b[3];
        b[4] = a[1]-b[2];
        b[5] = a[3]-b[0];
        
        if(b[5]==a[4]-b[4] && b[2]>=0 && b[3]>=0 && b[4]>=0 && b[5]>=0)
            return printf("1\n%d %d\n%d %d\n%d %d", b[0], b[1], b[2], b[3], b[4], b[5]);
    }
    
    printf("0");
}
