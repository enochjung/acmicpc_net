#include <stdio.h>

int t;
char a[210];

int main()
{
    for(scanf("%d",&t); t--;)
    {
        int i, j;
        bool d[210] = {1};
        scanf("%s", a);
        
        for(i=0; a[i]; i++)
            if(d[i]) {
                if(a[i]=='1' && a[i+1]=='0' && a[i+2]=='0') {
                    for(j=i+3; a[j]=='0'; j++);
                    for(; a[j]=='1'; j++)
                        d[j+1] = 1;
                }
                if(a[i]=='0' && a[i+1]=='1')
                    d[i+2] = 1;
            }
        
        printf("%s\n", d[i]?"YES":"NO");
    }
}
