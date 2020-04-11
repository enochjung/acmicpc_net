#include <cstdio>
#include <cstring>
#define N 10010

int* reverse(int* a)
{
	a[N-1]--;
	for(int i=N-1; i>=0; --i)
	{
		a[i] = 9-a[i];
		if(i > 0)
			a[i-1] -= a[i]/10;
		a[i] %= 10;
	}

	return a;
}

int* string_to_int_p(char* str)
{
	int *val, len;

	if(str[0] == '-')
		return reverse(string_to_int_p(str+1));
	
	val = new int[N]();
	len = (int)strlen(str);
	for(int i=N-len; i<N; ++i)
		val[i] = str[i+len-N]-'0';

	return val;
}

int* sum(int* a, int* b)
{
	int *val;

	val = new int[N]();
	for(int i=N-1; i>=0; --i)
	{
		val[i] += a[i]+b[i];
		if(i > 0)
			val[i-1] += val[i]/10;
		val[i] %= 10;
	}

	delete a;
	delete b;
	return val;
}

void print(int* a)
{
	if(a[0] == 9)
	{
		putchar('-');
		print(reverse(a));
		return;
	}

	bool start = false;
	bool is_printed = false;
	for(int i=0; i<N; ++i)
	{
		if(a[i] != 0)
			start = true;
		if(start)
		{
			putchar(a[i]+'0');
			is_printed = true;
		}
	}
	if(!is_printed)
		putchar('0');
	
	delete a;
}

int main()
{
	char a[N], b[N];
	int *ap, *bp;

	scanf("%s %s", a, b);
	ap = string_to_int_p(a);
	bp = string_to_int_p(b);
	print(sum(ap, bp));
	
	return 0;
}