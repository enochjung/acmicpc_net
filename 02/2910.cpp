#include <cstdio>
#include <algorithm>
#include <map>
#define N 1010

using namespace std;

int n, a[N];
map<int,int> cnt, first;

bool compare(int i, int j)
{
	return cnt[i]!=cnt[j]? cnt[i]>cnt[j] : first[i]<first[j];
}

int main()
{
	scanf("%d %*d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", a+i);

		++cnt[a[i]];
		if(first[a[i]] == 0)
			first[a[i]] = i+1;
	}

	sort(a, a+n, compare);
	
	for(int i=0; i<n; ++i)
		printf("%d ", a[i]);
	return 0;
}
