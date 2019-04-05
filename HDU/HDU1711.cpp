#include <cstdio>

int a[1000005],b[10005],next[10005],n,m,ans,ansn;

void get_next(int x[],int n)
{
    next[0]=0;
    for(int i=1,j=0;i<n;i++)
    {
        while(j&&x[i]!=x[j]) j=next[j-1];
        if(x[i]==x[j]) j++;
        next[i]=j;
    }
}

int kmp(int a[],int b[],int n,int m)
{
    get_next(b,m);
    for(int i=0,j=0;i<n;i++)
    {
        while(j&&b[j]!=a[i]) j=next[j-1];
        if(a[i]==b[j]) j++;
        if(j==m) return i-m+2;
    }
    return -1;
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        ans=ansn=0;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&b[i]);
        printf("%d\n",kmp(a,b,n,m));
    }
    return 0;
}