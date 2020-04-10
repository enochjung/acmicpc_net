#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int r, c;
char a[60][60];
int d[10];
bool v[60];
vector<int> p;

int main()
{
	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++)
		scanf("%s", a[i]);

	for(int i=0; i<r; i++)
		for(int j=1; j<c-1; j++)
			if('1'<=a[i][j] && a[i][j]<='9')
			{
				d[a[i][j]-'1'] = c-j;
				if(!v[c-j])
				{
					p.push_back(c-j);
					v[c-j] = true;
				}
				break;
			}

	sort(p.begin(), p.end());

	for(int i=0; i<9; i++)
		for(int j=0; j<(int)p.size(); j++)
			if(d[i] == p[j])
			{
				printf("%d\n", j+1);
				break;
			}

	return 0;
}
