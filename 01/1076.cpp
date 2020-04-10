#include <cstdio>
#include <cstring>

char a[3][10];
char t[10][10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
long long res;

int main()
{
	for(int i=0; i<3; i++)
		scanf("%s", a[i]);
	
	for(int i=0; i<10; i++)
		if(strcmp(a[0], t[i]) == 0)
			res = i*10;

	for(int i=0; i<10; i++)
		if(strcmp(a[1], t[i]) == 0)
			res += i;

	for(int i=0; i<10; i++)
		if(strcmp(a[2], t[i]) == 0)
			for(int j=0; j<i; j++)
				res *= 10;

	printf("%lld\n", res);
	return 0;
}
