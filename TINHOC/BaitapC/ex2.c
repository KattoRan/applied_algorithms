#include <stdio.h>
#include <string.h>
int nhuan(int y)
{
    if(y%4==0&&y%100!=0) return 1;
    if (y%400==0) return 1;
    return 0;
}
int hople(int y, int m, int d)
{
    if(m>12||m<1) return 0;
    switch(m)
    {
        case 1: case 3: case 5 : case 7: case 8: case 10: case 12:
        if(d>31) return 0; break;
        case 2: if(nhuan(y)&&(d>29)) return 0;
        if(!nhuan(y)&&(d>28)) return 0; break;
        default: if(d>30) return 0;
    }
    return 1;
}
int main()
{
    char s[100];
    scanf("%s", s);
    int n = strlen(s);
    if (n != 10 || s[4] != '-' || s[7] != '-')
    {
        printf("INCORRECT");
        return 0;
    }
    int year = 0, month = 0, day = 0;
    sscanf(s,"%d-%d-%d",&year,&month,&day);
    if (hople(year,month,day))
    printf("%d %d %d", year, month, day);
    else printf("INCORRECT");
    return 0;
}
