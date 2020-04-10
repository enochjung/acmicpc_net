#include <cstdio>
#include <set>
#include <string>

using namespace std;

char s[1010];
set<string> st;

int main()
{
	scanf("%s", s);

	for(int i=0; s[i]; i++)
	{
		string str;
		str.assign(s+i);
		st.insert(str);
	}

	for(auto it=st.begin(); it!=st.end(); ++it)
		printf("%s\n", it->c_str());
}
