#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;

int g(int x)
{
	int idx = (int)(upper_bound(v.begin(),v.end(),x)-v.begin()) - 1;
	if(x == v[idx])
		return x;
	return g(x-v[idx]);
}

int main()
{
	scanf("%d", &n);

	v.push_back(1);
	v.push_back(2);
	for(int i=0; v[i]<n; ++i)
		v.push_back(v[i]+v[i+1]);
	
	printf("%d", binary_search(v.begin(),v.end(),n)? -1 : g(n));
	return 0;
}
