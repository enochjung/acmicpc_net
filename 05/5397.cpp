#include <cstdio>
#include <list>

using namespace std;

int t;

int main()
{
	for(scanf("%d",&t), getchar(); t--;)
	{
		list<char> l;
		auto it = l.begin();

		while(1)
		{
			char c = getchar();
			if(c=='\n' || c=='\0')
				break;

			if(c == '<')
			{
				if(it != l.begin())
					--it;
			}
			else if(c == '>')
			{
				if(it != l.end())
					++it;
			}
			else if(c == '-')
			{
				if(it != l.begin())
					it = l.erase(--it);
			}
			else
				l.insert(it, c);
		}

		for(it=l.begin(); it!=l.end(); ++it)
			printf("%c", *it);
		printf("\n");
	}
	return 0;
}
