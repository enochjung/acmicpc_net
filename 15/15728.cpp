#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int n, k;
deque<int> a, b;

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		a.push_back(v);
	}
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		b.push_back(v);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	while(k--)
	{
		int p = max(a.front()*b.front(), a.back()*b.front());
		int q = max(a.front()*b.back(), a.back()*b.back());

		if(p > q)
			b.pop_front();
		else
			b.pop_back();
	}

	printf("%d", max({a.front()*b.front(), a.back()*b.front(), a.front()*b.back(), a.back()*b.back()}));
	return 0;
}
