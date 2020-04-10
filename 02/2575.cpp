#include <stdio.h>

int m, r;

int main()
{
    scanf("%d", &m);
    printf("%d ", (m+2)/3);
     
    switch(m)
    {
        case 1: r=1; break;
        default:
            while(m%4==0) r++, m/=4;
            if(m%2==0) r++, m/=2;
            for(int i=3; i<=m; i++)
                if(m%i==0) r++, m/=i--;
            break;
    }
    printf("%d", r);
}
