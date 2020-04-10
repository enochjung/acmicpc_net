#include <stdio.h>

char s[60];
bool check[30];
int res;

int main()
{
	scanf("%s", s);

	for(int i=0; i<52; i++)
	{
		int code = s[i]-'A';

		if(check[code] == false)
		{
			check[code] = true;
		}
		else
		{
			for(int j=i-1; s[j]!=s[i]; j--)
				if(check[s[j]-'A'] == true)
					res++;

			check[code] = false;
		}
	}

	printf("%d\n", res);

	return 0;
}
