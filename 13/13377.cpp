#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct st
{
	int no, ans;
	char s[10];
	bool operator<(const st &i) const {
		return strcmp(s, i.s)<0;
	}
} a[6010];

char c[] = "abcdefghi";
int n;

bool compare(const st &i, const st &j) {
	return i.no < j.no;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%s", a[i].s);
		a[i].no = i;
	}

	sort(a, a+n);

	int i=1, j=0;
	while(j<n)
	{
		if(strcmp(a[j].s, c) == 0)
		{
			a[j++].ans = i;
			continue;
		}
		i++;
		if(next_permutation(c, c+9) == false)
			break;
	};

	sort(a, a+n, compare);

	for(int i=0; i<n; i++)
		printf("%d\n", a[i].ans);
	return 0;
}
