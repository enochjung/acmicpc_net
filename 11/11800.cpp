#include <cstdio>

int t, a, b;
char s[20][20] = {"Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh", 
                  "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};

int main()
{
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d %d", &a, &b);
        if(a > b)
            a^=b^=a^=b;
        
        printf("Case %d: ", i);
        if(a == b)
            printf("%s\n", s[a-1]);
        else if(a==5 && b==6)
            printf("Sheesh Beesh\n");
        else
            printf("%s %s\n", s[b+5], s[a+5]);
    }
    return 0;
}
