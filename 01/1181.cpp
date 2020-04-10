#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string s[20010];

bool compare(const string &i, const string &j) {
	int la=i.length(), lb=j.length();
	return la!=lb? la<lb : i.compare(j)<0;
}

int main()
{
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> s[i];

	sort(s, s+n, compare);
	for(int i=0; i<n; i++)
		if(i==0 || s[i].compare(s[i-1])!=0)
			cout << s[i] << endl;
}
