#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
map<string, bool> m;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for(int i=0; i<n; ++i)
	{
		string name, state;
		cin >> name >> state;
		if(state.compare("enter") == 0)
			m[name] = true;
		else
			m.erase(name);
	}

	for(auto i=m.rbegin(); i!=m.rend(); ++i)
		cout << i->first << '\n';
	return 0;
}