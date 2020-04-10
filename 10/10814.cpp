#include <stdio.h>
#include <algorithm>

using namespace std;

struct st {
    int n, age;
    char name[110];
    bool operator<(const st &i) const {
        return (age==i.age)? n<i.n : age<i.age;
    }
} a[100010];

int n;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %s", &a[i].age, a[i].name);
        a[i].n = i;
    }
    
    sort(a, a+n);
    
    for(int i=0; i<n; i++)
        printf("%d %s\n", a[i].age, a[i].name);
}
