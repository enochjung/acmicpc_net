#include <cstdio>
#include <cstdlib>

int a, b, c, x, y;

int main()
{
    scanf("%d %d", &a, &b);
    c = abs(a-b);
    while((c&-c)>1) c>>=1;
    
    for(int i=0; i<5; i++) {
        scanf("%d %d", &x, &y);
        printf("%c\n", (c==0 && x==y) || ((a-b)*(x-y)>0 && abs(x-y)%c==0)?'Y':'N');
    }
	return 0;
}
