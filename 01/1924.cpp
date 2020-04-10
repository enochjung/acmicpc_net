#include <stdio.h>

int x, y;

int main()
{
    scanf("%d %d", &x, &y);
    
    switch(x) {
        case 12: y += 30;
        case 11: y += 31;
        case 10: y += 30;
        case 9: y += 31;
        case 8: y += 31;
        case 7: y += 30;
        case 6: y += 31;
        case 5: y += 30;
        case 4: y += 31;
        case 3: y += 28;
        case 2: y += 31;
    }
    
    switch(y%7) {
        case 0: printf("SUN"); break;
        case 1: printf("MON"); break;
        case 2: printf("TUE"); break;
        case 3: printf("WED"); break;
        case 4: printf("THU"); break;
        case 5: printf("FRI"); break;
        case 6: printf("SAT"); break;
    }
}
