#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> a, b;

int exponent(int x)
{
	int cnt = 1;
	for(; x; cnt*=10)
		x /= 10;
	return cnt;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		a.push_back(v);
	}
	a.push_back(99999);

	sort(a.begin(), a.end());

	for(int i=0; i<3; ++i)
		for(int j=i+1; j<4; ++j)
		{
			b.push_back(a[i] + a[j]*exponent(a[i]));
			b.push_back(a[i]*exponent(a[j]) + a[j]);
		} 

	sort(b.begin(), b.end());
	printf("%d", b[2]);

	return 0;
}
