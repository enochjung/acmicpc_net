#include <cstdio>
#include <cstring>

char s[5010];

bool pikachu(char* str)
{
	while(*str)
	{
		if(strncmp(str,"pi",2)==0 || strncmp(str,"ka",2)==0)
			str += 2;
		else if(strncmp(str,"chu",3) == 0)
			str += 3;
		else
			return false;
	}

	return true;
}

int main()
{
	scanf("%s", s);
	printf("%s", pikachu(s)? "YES" : "NO");
	return 0;
}
