#include <cstdio>

char s[30], a[]="aeiou";

int main()
{
	while(1)
	{
		scanf("%s", s);
		if(s[0] == '#')
			break;

		int i;
		for(i=0; s[i]; ++i)
		{
			bool found = false;
			for(int j=0; j<5; ++j)
				if(s[i] == a[j])
					found = true;
			if(found)
				break;
		}
		if(s[i] == 0)
			i = 0;
		printf("%s", s+i);
		s[i] = 0;
		printf("%say\n", s);
	}

	return 0;
}
