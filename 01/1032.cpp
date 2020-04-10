#include <stdio.h>

int n;
char s[60][60];
bool r[60];

int main()
{
	scanf("%d", &n);
    for(int i=0; i<n; i++)
		scanf("%d", s+i);
    
    for(int i=1; i<n; i++)
        for(int j=0; s[i][j]; j++)
            r[j] = r[j]|(s[i][j]!=s[i-1][j]);
    
    for(int i=0; s[0][i]; i++)
        printf("%c", r[i]? '?' : s[0][i]);
}
