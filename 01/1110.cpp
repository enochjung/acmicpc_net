#include <stdio.h>

int n, t, cnt;

int next(int v) {
    cnt++;
    return v%10*10+(v/10+v%10)%10;
}

int main()
{
	scanf("%d", &n);
    
    t = next(n);
    while(t != n)
        t = next(t);
    
	printf("%d", cnt);
}
