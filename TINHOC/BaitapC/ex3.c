#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char s[100000];
    scanf("%[^\n]s",s);
    int n = strlen(s);
    char t[30][100];
    int i=0,d=0;
    while(i<n)
    {
        if(s[i]-'A'>=0&&s[i]-'A'<26)
        {
            char *str=t[d++];
            *str = s[i];
            str++;
            i++;
            while(s[i]!=32&&s[i]!='.'&&s[i]!=',')
            {
                *str = s[i];
                str++;
                i++;
            }
            *str = '\0';
        }
        i++;
    }
    if (d==0) {printf("EMPTY");return 0;}
    for(int i = 0; i < d; i++)
        for (int j = i+1; j < d; j++)
            if (strcmp(t[i],t[j])>0)
    {
        char tmp[100];
        strcpy(tmp,t[i]);
        strcpy(t[i],t[j]);
        strcpy(t[j],tmp);
    }
    for(int i = 0; i < d; i++)
    {if (strcmp(t[i],t[i-1])==0) continue;
    printf("%s ",t[i]);}
}
