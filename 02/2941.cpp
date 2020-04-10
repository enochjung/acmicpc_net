#include <stdio.h>
#include <string.h>

char a[110], s[10][10]={"c=","c-","dz=","d-","lj","nj","s=","z="};
int res;

int main()
{
	scanf("%s", a);

	for(int i=0; a[i]; i++)
	{
		for(int j=0; j<8; j++)
		{
			int size = (int)strlen(s[j]);
			if(strncmp(a+i, s[j], size) == 0)
				i += size-1;
		}
		res++;
	}

	printf("%d\n", res);
	return 0;
}
