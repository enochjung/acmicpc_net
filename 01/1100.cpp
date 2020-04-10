#include <stdio.h>

int res;

int main()
{
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
		{
			char c;
			scanf(" %c", &c);
			if(c=='F' && (i+j)%2==0)
				res++;
		}

	printf("%d", res);
}
