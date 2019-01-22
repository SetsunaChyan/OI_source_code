#include <cstdio>

typedef long long ll;
struct node
{
    ll x,y,num;
}a[5005];
int n;

int main()
{
    scanf("%d",&n);
    int t=n;
    a[0].x=-100;
    a[n+1].x=(1ll<<40);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&a[i].x,&a[i].y);
        a[i].num=i;
    }
    for(int i=0;i<n;i++)
    {
        if(i&1)
            for(int j=t;j>=1;j--)
            {
                if(a[j-1].x<a[j].x-1&&a[j].x<a[j+1].x-1)
                {
                    printf("%lld\n",a[j].num);
                    for(int k=j;k<=t;k++)
                        a[k]=a[k+1];
                    t--;
                    break;
                }
            }
        else
            for(int j=1;j<=t;j++)
            {
                if(a[j-1].x<a[j].x-1&&a[j].x<a[j+1].x-1)
                {
                    printf("%lld\n",a[j].num);
                    for(int k=j;k<=t;k++)
                        a[k]=a[k+1];
                    t--;
                    break;
                }
            }
    }
    return 0;
}