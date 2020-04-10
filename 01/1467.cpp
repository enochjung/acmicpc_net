#include <cstdio>
#include <algorithm>
#include <list>
#define N 1010

using namespace std;

int n, m, mv, d[10];
list<int> l;

void input()
{
	char a[N], b[N];

	scanf("%s %s", a, b);
	for(; a[n]; ++n)
	{
		l.push_back(a[n]-'0');
		mv = max(mv, a[n]-'0');
	}
	for(; b[m]; ++m)
		++d[b[m]-'0'];
}

int main()
{
	input();

	for(int i=0; i<10; ++i)
		if(d[i])
		{
			if(i == mv)
			{
				auto it = l.end();
				--it;
				while(d[i])
				{
					if(*it == i)
					{
						it = l.erase(it);
						--d[i];
					}
					if(d[i])
						--it;
				}
			}
			else
			{
				auto it = l.begin();
				while(d[i])
				{
					if(*it == i)
					{
						it = l.erase(it);
						--d[i];
					}
					else
						++it;
				}
			}
		}

	bool zero = true;
	for(int v : l)
	{
		if(v != 0)
			zero = false;
		if(!zero)
			printf("%d", v);
	}
	if(zero)
		printf("0");

	return 0;
}
