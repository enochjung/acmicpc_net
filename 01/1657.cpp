#include <stdio.h>
#include <vector>

using namespace std;

int n, m;
char t[20][20];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%s", t[i]);

	return 0;
}
