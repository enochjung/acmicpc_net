#include <cstdio>
#include <cstring>

char s[510];

int main()
{
	while(1)
	{
		fgets(s, sizeof(s), stdin);
		if(strcmp(s, "END\n") == 0)
			break;

		for(int i=strlen(s)-2; i>=0; --i)
			putchar(s[i]);
		printf("\n");
	}

	return 0;
}
