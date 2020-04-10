#include <stdio.h>
#include <list>

using namespace std;

char s[100010];
int n;
list<char> l;
list<char>::iterator iter;

int main()
{
	scanf("%s", s);
	for(int i=0; s[i]; i++)
		l.push_back(s[i]);

	iter = l.end();
	scanf("%d", &n);
	while(n--)
	{
		char v;
		scanf(" %c", &v);
		switch(v)
		{
			case 'L':
				if(iter != l.begin())
					--iter;
				break;
			
			case 'D':
				if(iter != l.end())
					++iter;
				break;

			case 'B':
				if(iter != l.begin()) {
					list<char>::iterator imsi = iter;
					l.erase(--imsi);
				}
				break;

			case 'P':
				scanf(" %c", &v);
				l.insert(iter, v);
				break;
		}
	}
	
	for(iter = l.begin(); iter != l.end(); ++iter)
		printf("%c", *iter);
}
