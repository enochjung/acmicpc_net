#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<string> v;

int main()
{
	cin >> n >> m;
	for(int i=0; i<n; ++i)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end());
	cout << v[m-1];
	return 0;
}