#include <cstdio>
#include <cstring>

char s[110];

int main()
{
	scanf("%s", s);

	for(int i=0; i<26; i++)
	{
		char* idx = strchr(s,'a'+i);
		printf("%d ", idx==NULL? -1 : (int)(idx-s));
	}
	return 0;
}
