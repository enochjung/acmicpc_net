#include <cstdio>

int o[10][10];

int error_code(int id)
{
	return o[o[o[o[0][id/1000]][id/100%10]][id/10%10]][id%10];
}

int check(int ssn)
{
	return o[o[o[o[o[0][ssn/10000]][ssn/1000%10]][ssn/100%10]][ssn/10%10]][ssn%10];
}

void int_to_str(int ssn, char* s)
{
	for(int i=4; i>=0; --i)
	{
		s[i] = ssn%10+'0';
		ssn /= 10;
	}
}

int str_to_int(char* s)
{
	int val = 0;
	for(int i=0; i<5; ++i)
	{
		val *= 10;
		val += s[i]-'0';
	}
	return val;
}

bool error(int ssn)
{
	char str[6] = {};

	for(int p=0; p<5; ++p)
	{
		int_to_str(ssn, str);
		for(int i=0; i<10; ++i)
		{
			str[p] = '0'+i;
			int he = str_to_int(str);
			if(he!=ssn && check(he)==0)
				return true;
		}
	}

	for(int i=0; i<4; ++i)
	{
		int_to_str(ssn, str);
		str[i]^=str[i+1]^=str[i]^=str[i+1];
		int he = str_to_int(str);
		if(he!=ssn && check(he)==0)
			return true;
	}

	return false;
}

int main()
{
	for(int i=0; i<10; ++i)
		for(int j=0; j<10; ++j)
			scanf("%d", &o[i][j]);

	int res = 0;
	for(int id=0; id<10000; ++id)
	{
		int ssn = id*10 + error_code(id);
		if(error(ssn))
			++res;
	}

	printf("%d", res);
	return 0;
}
