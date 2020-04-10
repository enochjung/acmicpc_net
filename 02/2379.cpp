#include <cstdio>
#include <cstdlib>
#define R 3001

int t, idx;
char s[3010];

int code()
{
    int sum = 1;
    
    while(s[idx++] == '0')
        sum = (sum+code())%R;
    
    return (sum*sum)%R;
}

int main()
{
    for(scanf("%d",&t); t--;)
    {
		int res[2];

        for(int i=0; i<2; ++i)
        {
            idx = 0;
            scanf("%s", s);
			res[i] = code();
        }
        
        printf("%d\n", res[0]==res[1]);
    }
    
    return 0;
}
