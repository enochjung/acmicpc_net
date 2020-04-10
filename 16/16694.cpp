#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define L 300010

using namespace std;

int l, d[L];
char s[L];

class aho_corasick
{
private:
	static const int MAX_CHAR = 26;

	vector<vector<int>> go;
	vector<int> fail;
	vector<int> finish;

public:
	aho_corasick(vector<string> &target)
	{
		go.push_back(vector<int>(MAX_CHAR, 0));
		fail.push_back(0);
		finish.push_back(0);

		for(string str : target)
		{
			int p = 0;
			for(char ch : str)
			{
				if(!go[p][ch-'a'])
				{
					go[p][ch-'a'] = go.size();
					go.push_back(vector<int>(MAX_CHAR, 0));
					fail.push_back(0);
					finish.push_back(0);
				}
				p = go[p][ch-'a'];
			}
			finish[p] = str.length();
		}

		queue<int> q;
		q.push(0);
		while(!q.empty())
		{
			int now = q.front();
			q.pop();

			for(int i=0; i<MAX_CHAR; ++i)
				if(go[now][i])
				{
					int x = now;
					int y = go[x][i];
					q.push(y);

					while(x && !go[fail[x]][i])
						x = fail[x];
					fail[y] = x? go[fail[x]][i] : 0;
					finish[y] = max(finish[y], finish[fail[y]]);
				}
		}
	}

	void solve(string str, int d[])
	{
		int x = 0;
		
		for(int i=0; i<(int)str.size(); ++i)
		{
			while(x && !go[x][str[i]-'a'])
				x = fail[x];
			x = go[x][str[i]-'a'];
			d[i-finish[x]+1] = max(d[i-finish[x]+1], finish[x]);
		}
	}
};

int main()
{
	scanf("%d %s", &l, s);

	vector<string> v;
	for(int i=0; i<l; ++i)
	{
		char t[L];
		scanf("%s", t);
		v.push_back(t);
	}

	aho_corasick aho(v);
	aho.solve(s, d);
	if(d[0] == 0)
	{
		printf("-1");
		return 0;
	}

	int len = (int)strlen(s);
	int res = 1;
	int x = 0;
	while(x+d[x] < len)
	{
		int mi=x+d[x], idx=-1;
		for(int i=x+1; i<=x+d[x]; ++i)
			if(mi < i+d[i])
			{
				mi = i+d[i];
				idx = i;
			}
		if(idx == -1)
		{
			printf("-1");
			return 0;
		}
		x = idx;
		++res;
	}
	printf("%d", res);
	return 0;
}
