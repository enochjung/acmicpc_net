#include <cstdio>

int a[10];
int check;

int main()
{
	for(int i=0; i<8; i++)
		scanf("%d", a+i);

	for(int i=0; i<7; i++)
	{
		if(a[i] < a[i+1])
			check |= 1;
		else
			check |= 2;
	}

	printf("%s\n", check==1? "ascending" : (check==2? "descending" : "mixed"));
}
