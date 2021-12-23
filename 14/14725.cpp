#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define N 1000

using namespace std;

class tree
{
private:
	map<string,tree*> m;

public:
	tree* insert(string s)
	{
		if (m.find(s) != m.end())
			return m[s];

		tree* child = new tree();
		m[s] = child;
		return child;
	}
	void print(int level)
	{
		for (auto it=m.begin(); it!=m.end(); ++it)
		{
			for (int i=0; i<level; ++i)
				cout << "--";
			cout << it->first << '\n';
			it->second->print(level+1);
		}
	}
};

int main()
{
	int n;
	tree* root = new tree();

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	while (n--)
	{
		int num;
		tree* t = root;

		cin >> num;
		while (num--)
		{
			string str;
			cin >> str;
			t = t->insert(str);
		}
	}

	root->print(0);
	return 0;
}