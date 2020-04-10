#include <stdio.h>

char a[1000010], res;
int cnt[26], max;

int main()
{
    scanf("%s", a);
    
    for(int i=0; a[i]; i++)
        cnt[a[i]>='a'? a[i]-'a' : a[i]-'A']++;
    
    for(int i=0; i<26; i++) {
        if(cnt[i] > max) {
            max = cnt[i];
            res = 'A'+i;
        }
        else if(cnt[i] == max)
            res = '?';
    }
    printf("%c", res);
}
