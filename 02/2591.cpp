#include <cstdio>
#include <cstring>

char a[50];
int n, d[50];

int main()
{
	scanf("%s", a+1);
	n = (int)strlen(a+1);

	d[0] = d[1] = (a[1]=='0'? 0 : 1);
	for(int i=2; i<=n; i++)
	{
		if(a[i]=='0' && (a[i-1]>'3' || a[i-1]=='0'))
			d[i] = d[i-1] = 0;
		else if(a[i] == '0')
			d[i] = d[i-2];
		else if(((a[i-1]-'0')*10+(a[i]-'0')>34) || a[i-1]=='0')
			d[i] = d[i-1];
		else
			d[i] = d[i-2]+d[i-1];
	}

	printf("%d", d[n]);
	return 0;
}
