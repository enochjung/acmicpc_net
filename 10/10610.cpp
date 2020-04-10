#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#define N 100010

using namespace std;

int n;
char s[N];

int main()
{
	scanf("%s", s);
	n = (int)strlen(s);

	sort(s, s+n, greater<char>());
	
	int sum = 0;
	for(int i=0; i<n; ++i)
		sum += s[i]-'0';

	if(sum%3==0 && s[n-1]=='0')
		printf("%s", s);
	else
		printf("-1");
	return 0;
}
