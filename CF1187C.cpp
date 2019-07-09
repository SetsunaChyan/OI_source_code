#include <bits/stdc++.h>
using namespace std;

int l[1005],r[1005],t[1005],n,m,a[1005];

bool check(int l,int r)
{
    bool ret=false;
    for(int i=l;i<=r;i++)
    {
        if(a[i]==0) a[i]=a[i-1]-1;
        if(i!=l&&a[i]<a[i-1]) ret=true;
    }
    return ret;
}

int main()
{
    memset(a,0,sizeof(a));
    a[0]=100000000-1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&t[i],&l[i],&r[i]);
        if(t[i])
        {
            int flag=0;
            for(int j=r[i];j>=l[i];j--)
                if(a[j]) {flag=j;break;}
            if(flag)
            {
                for(int j=flag;j>=l[i];j--)
                    a[j]=a[flag]-(flag-j);
                for(int j=flag;j<=r[i];j++)
                    a[j]=a[flag]-(flag-j);
            }
            else
            {
                for(int j=l[i];j<=r[i];j++)
                    a[j]=(n+1)*(n+1)+114514-(n+1)*l[i]+j;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        if(!t[i]&&!check(l[i],r[i]))
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)
    {
        if(!a[i]) a[i]=1;
        printf("%d ",a[i]);
    }
    return 0;
}

/*
10 10
1 9 10
1 8 9
1 7 8
1 4 5
1 2 3
1 1 2
0 1 10
0 4 6
0 1 10
0 1 10


*/
