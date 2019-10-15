#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[100005],ans,num,vis[100005],qaq[100005],mx;
ll who[100005],bit[100005];

void add(ll bit[],int x,int y)
{
    for(;x<=n;x+=x&-x) bit[x]+=y;
}

ll sum(ll bit[],int x)
{
    ll ret=0;
    for(;x;x-=x&-x) ret+=bit[x];
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        if(mx<a[i]) qaq[a[i]]=1;
        mx=max(a[i],mx);
    }
    for(int i=0;i<n;i++)
    {
        add(bit,a[i],1);
        add(who,a[i],a[i]);
        if(sum(bit,n)-sum(bit,a[i])==1)
            vis[sum(who,n)-sum(who,a[i])]++;
    }
    ans=-0x3f3f3f3f;
    for(int i=1;i<=n;i++)
        if(vis[i]-qaq[i]>ans) num=i,ans=vis[i]-qaq[i];
    printf("%d",num);
    return 0;
}
