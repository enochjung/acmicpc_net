#include <cstdio>
#include <cstring>

int m, k;
char s[210], b[20][30];

int main()
{
	scanf("%d %s", &k, s);
	m = (int)strlen(s)/k;

	int idx = 0;
	for(int i=0; i<m; ++i)
		for(int j=i&1?k-1:0; 0<=j&&j<k; j+=i&1?-1:1)
			b[i][j] = s[idx++];

	for(int j=0; j<k; ++j)
		for(int i=0; i<m; ++i)
			printf("%c", b[i][j]);
	return 0;
}
