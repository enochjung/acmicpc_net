#include <cstdio>
#include <cstring>

int n, a[26];
char s[60];

int main()
{
	scanf("%s", s);
	n = (int)strlen(s);

	for(int i=0; i<n; i++)
		a[s[i]-'A']++;

	int idx = -1;
	for(int i=0; i<26; i++)
		if(a[i] & 1)
		{
			if(idx != -1)
			{
				printf("I'm Sorry Hansoo\n");
				return 0;
			}
			idx = i;
		}

	for(int i=0; i<26; i++)
		for(int j=0; j<a[i]/2; j++)
			printf("%c", 'A'+i);
	if(idx != -1)
		printf("%c", 'A'+idx);
	for(int i=25; i>=0; i--)
		for(int j=0; j<a[i]/2; j++)
			printf("%c", 'A'+i);
	printf("\n");
	return 0;
}
