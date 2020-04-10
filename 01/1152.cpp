#include <stdio.h>

char s[100010];
bool sp = true;
int cnt;

int main()
{
    fgets(a, sizeof(a), stdin);
    
    for(int i=0; a[i]!='\n' && a[i]!=0; i++)
    {
        if(a[i] == ' ')
            sp = true;
        else if(sp)
            cnt++, sp=false;
    }
    
    printf("%d", cnt);
}
