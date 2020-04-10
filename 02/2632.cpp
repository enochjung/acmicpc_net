#include <stdio.h>
#include <map>

using namespace std;

int s, m, n, res;
int a[1010], b[1010];
map<int,int> ma, mb;

int main()
{
    scanf("%d %d %d", &s, &m, &n);
    for(int i=0; i<m; i++)
        scanf("%d", a+i);
    for(int i=0; i<n; i++)
        scanf("%d", b+i);
    
    for(int i=0; i<m; i++) {
        int sum = 0;
        for(int j=0; j<m-1; j++) {
            sum += a[(i+j)%m];
            ma[sum]++;
        }
        if(i == m-1)
            ma[sum+a[(i+m-1)%m]] = 1;
    }
    
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=0; j<n-1; j++) {
            sum += b[(i+j)%n];
            mb[sum]++;
        }
        if(i == n-1)
            mb[sum+b[(i+n-1)%n]] = 1;
    }
    
    res = ma[s]+mb[s];
    for(map<int,int>::iterator it=ma.begin(); it!=ma.end() && it->first<s; ++it)
        res += it->second*mb[s-it->first];
    printf("%d", res);
}
