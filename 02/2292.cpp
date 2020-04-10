#include <cstdio>

int n;

int main()
{
    scanf("%d", &n);
    for(int i=1; ; i++)
        if(n <= 6*((i-1)*i/2)+1)
		{
			printf("%d\n", i);
			break;
		}
	return 0;
}
