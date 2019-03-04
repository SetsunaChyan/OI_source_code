#include <cstdio>

int n,s[2000];

void build(int l,int r)
{
    int a=0,b=0;
    for(int i=l;i<=r;i++)
        if(s[i]) a++; else b++;
    int m=(l+r)>>1;
    if(l!=r)
    { 
        build(l,m);
        build(m+1,r);
    }
    if(!b) printf("I"); 
    else if(!a) printf("B");
    else printf("F");
}

int main()
{
    scanf("%d",&n);
    n=1<<n;
    for(int i=0;i<n;i++)
        scanf("%1d",&s[i]);
    build(0,n-1);
    return 0;
}