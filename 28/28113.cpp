#include <cstdio>

int main() {
    int a, b;

    scanf("%*d %d %d", &a, &b);

    if (a < b)
        printf("Bus\n");
    else if (a > b)
        printf("Subway\n");
    else
        printf("Anything\n");

    return 0;
}