#include <stdio.h>
#include <string.h>

char a[60], m[60]; // m[i] : i~n-1까지의 문자 중 가장 작은 문자
int n;

char min(char x,char y){return x<y?x:y;}

*char[60] f(int x) {
    char[60] *aa = new char[60];
    return aa;
}

int main()
{
    scanf("%s", a);
    n = (int)strlen(a);
    
    m[n] = 'z';
    for(int i=n-1; i>=0; i--)
        m[i] = min(m[i+1], a[i]);
}
