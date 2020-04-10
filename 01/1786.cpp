#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_N 1000010
#define MAX_M 1000010

using namespace std;

char t[MAX_N], p[MAX_M];

vector<int> kmp(char *s, int N, char *w, int M)
{
	int fail[MAX_M] = {};

	for(int i=1,j=0; i<N; ++i)
	{
		while(j && w[i]!=w[j])
			j = fail[j-1];
		if(w[i] == w[j])
			fail[i] = ++j;
	}

	vector<int> ret;
	for(int i=0, j=0; i<N; ++i)
	{
		while(j && s[i]!=w[j])
			j = fail[j-1];
		if(s[i] == w[j])
		{
			if(j == M-1)
			{
				ret.push_back(i-M+1);
				j = fail[j];
			}
			else ++j;
		}
	}
	return ret;
}

int main()
{
	scanf("%[^\n]", t);
	getchar();
	scanf("%[^\n]", p);
	vector<int> r = kmp(t, strlen(t), p, strlen(p));
	printf("%d\n", (int)r.size());
	for(int v : r)
		printf("%d ", v+1);
    return 0;
}
