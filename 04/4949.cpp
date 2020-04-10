#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char str[110];

int main()
{
	while(1)
	{
		stack<char> s;
		scanf("%[^\n]%*c", str);
		if(strcmp(str, ".") == 0)
			break;

		bool success = true;
		for(int i=0; str[i]; ++i)
		{
			switch(str[i])
			{
				case '(':
				case '[':
					s.push(str[i]);
					break;

				case ')':
					if(s.empty() || s.top()!='(')
						success = false;
					else
						s.pop();
					break;

				case ']':
					if(s.empty() || s.top()!='[')
						success = false;
					else
						s.pop();
					break;
			}
		}
		if(!s.empty())
			success = false;

		printf("%s\n", success? "yes" : "no");
	}
	return 0;
}
