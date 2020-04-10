#include <iostream>
#include <set>
#include <string>

using namespace std;

int n, m;
set<string> a, b;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	while(n--)
	{
		string s;
		cin >> s;
		a.insert(s);
	}
	while(m--)
	{
		string s;
		cin >> s;
		if(a.find(s) != a.end())
			b.insert(s);
	}
	cout << b.size() << '\n';
	for(auto s : b)
		cout << s << '\n';
	return 0;
}
