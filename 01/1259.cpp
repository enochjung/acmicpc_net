#include <cstdio>
#include <cstring>
#define N 6

bool f(char s[])
{
	int len = (int)strlen(s);

	for (int i=0; i<len/2; ++i)
		if (s[i] != s[len-i-1])
			return false;
	return true;
}

int main()
{
	char s[N];

	while (true)
	{
		scanf("%s", s);
		if (strcmp(s, "0") == 0)
			break;
		
		printf("%s\n", f(s)? "yes" : "no");
	}

	return 0;
}