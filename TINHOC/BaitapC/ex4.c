#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int fi,se;
} pair;
int cmp(const void* a, const void* b)
{
    const pair *aa=(pair*)a;
    const pair *bb=(pair*)b;
    if (aa->fi == bb->fi) return (aa->se - bb->se);
    return (aa->fi - bb->fi);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int d[100001]={0};
    int **c = NULL;
    c = (int **)malloc(m * sizeof(int *));
    for (int i = 1; i <= n; i++)
    {
        // Cấp phát cho từng con trỏ cấp 1
        c[i] = (int *)malloc(m * sizeof(int));
    }
    pair cap[100001];
    for (int i = 1; i <= m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a<b) {cap[i].fi = a;cap[i].se=b;}
        else {cap[i].fi = b;cap[i].se=a;}
    }
    qsort(cap,m+1,sizeof(pair),cmp);
    for (int i = 1; i <= m; i++)
    {
        int a,b;
        a = cap[i].fi; b=cap[i].se;
        //printf("%d %d\n",a,b);
        c[a][d[a]++]=b;
        c[b][d[b]++]=a;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < d[i]; j++)
            printf("%d ",c[i][j]);
        free(c[i]);
        printf("\n");
    }
    free(c);
}
