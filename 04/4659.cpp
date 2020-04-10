#include <cstdio>
#include <cstring>

char s[30];

bool is_vowel(char c)
{
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

bool f()
{
	int n = (int)strlen(s);

	if(n<3 && !is_vowel(s[0]) && !is_vowel(s[1]))
		return false;

	int cc=0, vc=0;
	for(int i=0; i<n; ++i)
	{
		if(is_vowel(s[i]))
			++vc, cc=0;
		else
			++cc, vc=0;
		if(cc>2 || vc>2)
			return false;
		if(s[i]==s[i+1] && s[i]!='e' && s[i]!='o')
			return false;
	}

	return true;
}

int main()
{
	while(true)
	{
		scanf("%s", s);
		if(strcmp(s, "end") == 0)
			break;
		printf("<%s> is %sacceptable.\n", s, f()? "" : "not ");
	}

	return 0;
}
