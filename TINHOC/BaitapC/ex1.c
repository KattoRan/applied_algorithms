#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char s[1000], t[1000];
    if(fgets(s,1000,stdin)!=NULL)
    {int n = strlen(s);
    while( s[n-1] == 10 ) {s[n-1]=0;n--;}
    char *str = t;
    for (int i = 0; i < n; i++)
    {
        if (s[i]!=' '&&s[i]!='\t')
        {
            *str = s[i];
            str++;
        }
        else
            {
                if (s[i-1]=='\t'||s[i-1]==' '||i==0) continue;
                else {*str = ' ';str++;}
            }

    }
    *str = '\0';
    if(strlen(t)){
        //printf("%c",t[0]);
    if(t[0]-'a'>=0&&t[0]-'a'<26) t[0]-=32;
    printf("%s",t);}
    else printf("EMPTY");}
    else printf("EMPTY");
    return 0;

}
