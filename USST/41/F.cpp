#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct node
{
    ll x,y;
}a[300005];
ll mul=1,sum=0,ans=0,last=-1;
int n,q,w,used=0;

bool cmp(node a,node b){return a.x-a.y>b.x-b.y;};

int main()
{
    scanf("%d%d%d",&n,&q,&w);
    for(int i=0;i<q;i++) mul*=2;
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&a[i].x,&a[i].y);
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
        if(a[i].y<a[i].x&&i<w) sum+=a[i].x,last=i,used++; else sum+=a[i].y;
    ans=sum;
    for(int i=0;i<n;i++)
    {
        if(a[i].y<a[i].x&&i<w)
            ans=max(ans,sum+a[i].x*mul-a[i].x);
        else
        {
            if(~last&&used==w)
                ans=max(ans,sum-a[last].x+a[last].y+a[i].x*mul-a[i].y);
            else if(w)
                ans=max(ans,sum-a[i].y+a[i].x*mul);
        }
    }
    printf("%lld",ans);
    return 0;
} 