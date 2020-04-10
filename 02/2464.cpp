#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

void ntob(long long n, char b[99])
{
	int i;
	for(i=0; n; i++,n>>=1)
		b[i] = (n&1) + '0';
	reverse(b, b+i);
}

long long bin(const char b[100])
{
	long long n = 0;
	for(int i=0; b[i]; i++)
	{
		n <<= 1;
		n += b[i]-'0';
	}
	return n;
}

int main()
{
	long long n;
	char b[100]={}, bt[100]={};

	scanf("%lld", &n);

	b[0] = '0';
	ntob(n, b+1);	
	
	int len = (int)strlen(b);

	strcpy(bt, b);
	if(prev_permutation(bt, bt+len) == false)
		printf("0 ");
	else
		printf("%lld ", bin(bt));

	strcpy(bt, b);
	next_permutation(bt, bt+len);
	printf("%lld\n", bin(bt));
	
	return 0;
}
