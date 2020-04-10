#include <stdio.h>
#include <string.h>

char a[1000010];
int n;

int main()
{
    scanf("%s", a);
    n=(int)strlen(a);
    
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum <<= 1;
        sum += (a[i]-'0');
        if((n-i-1)%3 == 0) {
            printf("%d", sum);
            sum = 0;
        }
    }
}
