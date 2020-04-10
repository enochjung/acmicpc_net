#include <stdio.h>
#define LIMIT 1000000

using namespace std;

int n;
int res[1010][6] = {1};
int sum;

int main()
{
	scanf("%d", &n);
    
    for(int i=1; i<=n; i++) {
        res[i][0] = (res[i-1][0]+res[i-1][1]+res[i-1][2])%LIMIT;
        res[i][1] = res[i-1][0];
        res[i][2] = res[i-1][1];
        res[i][3] = (res[i-1][0]+res[i-1][1]+res[i-1][2]+res[i-1][3]+res[i-1][4]+res[i-1][5])%LIMIT;
        res[i][4] = res[i-1][3];
        res[i][5] = res[i-1][4];
    }
    
    for(int i=0; i<6; i++)
        sum += res[n][i];
    
    printf("%d", sum%LIMIT);
}
