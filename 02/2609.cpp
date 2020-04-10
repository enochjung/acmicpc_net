#include <stdio.h>

int a, b, g;

int gcd(int n, int m)
{
    while(m > 0) {
        int t = n;
        n = m;
        m = t%m;
    }
    return n;
}

int main()
{
    cin >> a >> b;
    
    if(a<b) a^=b^=a^=b;
    g = gcd(a, b);
    
    cout << g << endl << a*b/g;
}
