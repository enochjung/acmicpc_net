#include <cstdio>
#include <cstring>

char a[20];
bool fbi;

int main()
{
	for(int i=0; i<5; ++i)
	{
		scanf("%s", a);
		if(strstr(a, "FBI") != nullptr)
		{
			printf("%d\n", i+1);
			fbi = true;
		}
	}

	if(!fbi)
		printf("HE GOT AWAY!");
	return 0;
}
