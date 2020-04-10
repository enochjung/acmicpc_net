#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n, a[500010];
int sum;
map<int,int> m;
vector<int> res;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", a+i);
		sum += a[i];
		m[a[i]]++;
	}

	sort(a, a+n);

	int v = 0;
	for(auto it=m.begin(); it!=m.end(); ++it)
	{
		if(v < it->second)
		{
			v = it->second;
			res.clear();
			res.push_back(it->first);
		}
		else if(v == it->second)
			res.push_back(it->first);
	}

	sort(res.begin(), res.end());

	printf("%.0lf\n", (double)sum/n);
	printf("%d\n", a[(n-1)/2]);
	printf("%d\n", (int)res.size()>1? res[1] : res[0]);
	printf("%d\n", a[n-1]-a[0]);
	return 0;
}
