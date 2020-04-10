#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

char s[210];
string str;
int len;
vector<string> res;

void f(int i, int lv, int c)
{
	if(i == len) {
		res.push_back(str);
		return;
	}
	
	switch(s[i])
	{
		case '(':
			str.push_back(s[i]);
			f(i+1, lv+1, c);
			str.pop_back();
			f(i+1, lv+1, c|(1<<lv));
			break;

		case ')':
			if(c&(1<<(lv-1)))
				f(i+1, lv-1, c^(1<<(lv-1)));
			else {
				str.push_back(s[i]);
				f(i+1, lv-1, c);
				str.pop_back();
			}
			break;

		default:
			str.push_back(s[i]);
			f(i+1, lv, c);
			str.pop_back();
	}
}

int main()
{
	scanf("%s", s);
	len = (int)strlen(s);
	f(0, 0, 0);
	sort(res.begin(), res.end());
	for(int i=1; i<res.size(); i++)
		if(res[i].compare(res[i-1]) != 0)
			printf("%s\n", res[i].c_str());
}
