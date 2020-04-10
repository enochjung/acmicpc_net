#include <cstdio>
#include <vector>

using std::vector;

char a[70];
long long k;
vector<int> v;

char upper(char x)
{
	return (x-'0')%5+5+'0';
}

char lower(char x)
{
	return (x-'0')%5+'0';
}

int main()
{
	scanf("%s %lld", a, &k);
	--k;

	for(int i=0; a[i]; ++i)
		if(((a[i]-'0')%5+1)/2 == 1)
			v.push_back(i);

	if(k<0 || k>=1LL<<v.size())
	{
		printf("-1");
		return 0;
	}

	for(int i=v.size()-1; i>=0; --i,k>>=1)
		a[v[i]] = k&1? upper(a[v[i]]) : lower(a[v[i]]); 

	printf("%s", a);
	return 0;
}
