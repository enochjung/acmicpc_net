#include <cstdio>
#include <set>

using namespace std;

int n, d[250010];
long long res;
set<int> s;

int max(int a, int b)
{
	return a>b? a : b;
}

int main()
{
	scanf("%d", &n);

	while(n--)
	{
		int v;
		scanf("%d", &v);

		if(s.empty())
		{
			s.insert(v);
			d[v] = 1;
		}
		else
		{
			auto it = s.insert(v).first;
			auto ita=it, itb=it;

			if(it == s.begin())
			{
				++itb;
				d[v] = d[*itb]+1;
			}
			else if(it == (--s.end()))
			{
				--ita;
				d[v] = d[*ita]+1;
			}
			else
			{
				--ita, ++itb;
				d[v] = max(d[*ita], d[*itb])+1;
			}
		}

		res += d[v];
	}

	printf("%lld\n", res);
	return 0;
}
