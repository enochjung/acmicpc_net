#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int r, n;
char s[53][12];
int c[53], left, right;

int dist(int x)
{
	return min({x, abs(x-r/2-1), r+2-x});
}

int main()
{
	scanf("%d %d", &r, &n);
	for(int i=0; i<r+3; ++i)
	{
		scanf("%s", s[i]);
		for(int j=0; j<11; ++j)
			if(s[i][j] == '-')
			{
				++c[i];
				j<5? ++left : 0;
				j>5? ++right : 0;
			}
	}

	for(int p=0; p<n; ++p)
	{
		vector<int> target;

		for(int i=1; i<r+2; ++i)
			if(i!=r/2+1 && c[i])
				target.push_back(i);

		int row = accumulate(next(target.begin()), target.end(), target[0], [](int a, int b)
		{
			int pa = a%(r/2+1);
			int pb = b%(r/2+1);
			int da = dist(a);
			int db = dist(b);
			bool flag = (pa<2)^(pb<2)? pa<pb : (c[a]!=c[b]? c[a]>c[b] : (da!=db? da<db : a<b));
			return flag? a : b;
		});

		target = {1, 3, 5, 0, 4};

		int col = 5+accumulate(target.begin(), target.end(), 9, [row](int a, int b)
		{
			int c = left<right? b : -b;
			return a<9? a : (s[row][5+c]=='-'? c : (s[row][5-c]=='-'? -c : 9));
		});

		s[row][col] = 'a'+p;
		--c[row];
		col<5? --left : 0;
		col>5? --right : 0;
	}

	for(int i=0; i<r+3; ++i)
		printf("%s\n", s[i]);

	return 0;
}
