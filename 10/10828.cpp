#include <cstdio>
#include <stack>

using namespace std;

int n;
char a[10];
int b;
stack<int> s;

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", a);
		switch(a[0])
		{
		case 'p':
			if(a[1] == 'u')
			{
				scanf("%d", &b);
				s.push(b);
			}
			else
			{
				if(s.empty())
					printf("-1\n");
				else
				{
					printf("%d\n", s.top());
					s.pop();
				}
			}
			break;

		case 's':
			printf("%d\n", (int)s.size());
			break;
			
		case 'e':
			printf("%d\n", s.empty());
			break;

		case 't':
			if(s.empty())
				printf("-1\n");
			else
				printf("%d\n", s.top());
			break;
		}
	}
	return 0;
}
