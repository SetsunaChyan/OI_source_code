#include <cstdio>

const int rule[5][5]={{0,0,1,1,0},
                      {1,0,0,1,0},
                      {0,1,0,0,1},
                      {0,0,1,0,1},
                      {1,1,0,0,0}};
int n,na,nb,a[200],b[200];

int main()
{
    int i,sa=0,sb=0;
    scanf("%d%d%d",&n,&na,&nb);
    for(i=0;i<na;i++) scanf("%d",&a[i]);
    for(i=0;i<nb;i++) scanf("%d",&b[i]);
    for(i=0;i<n;i++)
    {
        sa+=rule[a[i%na]][b[i%nb]];
        sb+=rule[b[i%nb]][a[i%na]];
    }
    printf("%d% d",sa,sb);
    return 0;
}
