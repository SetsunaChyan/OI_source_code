#include <bits/stdc++.h>
using namespace std;

const int UP=1<<25;
int n,a[100005],flag,ans=0x3f3f3f3f,sum;

int cal(int x,int y)
{
    int t=x,stp=0;
    while(t!=y&&t<UP)
    {
        stp++;
        t<<=1;
    }
    if(t==y) return stp;
    t=x,stp=0;
    while(t!=y&&t>1)
    {
        stp++;
        t>>=1;
        int stp2=stp,t2=t;
        while(t2!=y&&t2<UP)
        {
            stp2++;
            t2<<=1;
        }
        if(t2==y) return stp2;
    }
    if(t==y) return stp;
    return -1;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=100000;i++)
    {
        flag=0,sum=0;
        for(int j=0;j<n;j++)
        {
            int k=cal(a[j],i);
            if(k==-1)
            {
                flag=1;
                break;
            }
            sum+=k;
        }
        if(!flag) ans=min(ans,sum);
    }
    printf("%d",ans);
    return 0;
}