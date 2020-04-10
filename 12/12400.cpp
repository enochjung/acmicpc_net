#include <cstdio>

int t;
char s[110];
char to[30] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	scanf("%d", &t);
	for(int tt=1; tt<=t; ++tt)
	{
		getchar();
		scanf("%[^\n]", s);
		printf("Case #%d: ", tt);
		for(int i=0; s[i]; ++i)
		{
			if(s[i] != ' ')
				printf("%c", to[s[i]-'a']);
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
