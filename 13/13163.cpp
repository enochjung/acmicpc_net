#include <cstdio>

int n;

int main()
{
	for(scanf("%d",&n); n--;)
	{
		char c;
		while((c=getchar()) != ' ');
		printf("god");
		while((c=getchar()) != '\n')
			if(c != ' ')
				printf("%c", c);
		printf("\n");
	}
	return 0;
}
