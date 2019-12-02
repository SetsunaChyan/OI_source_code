#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int m,n,k,t,a[200005];
ll dp[200005][2];
struct node
{
    int L,R,D;
}p[200005];
vector<node> v;

inline bool cmp(node a,node b)
{
    if(a.L==b.L) return a.R>b.R;
    return a.L<b.L;
}

bool check(int x)
{
    v.clear();
    v.push_back({0,0,0});
    int last=0;
    for(int i=0;i<k;i++)
        if(p[i].D>x&&p[i].R>last) v.push_back(p[i]),last=p[i].R;
    dp[0][0]=dp[0][1]=0;
    for(int i=1;i<v.size();i++)
    {
        dp[i][0]=min(dp[i-1][0],dp[i-1][1])+2*(v[i].R-v[i-1].R);
        dp[i][1]=min(dp[i-1][0],dp[i-1][1])+2*(v[i].R-v[i].L+1);
    }
    //printf("! %d %lld\n",x,min(dp[v.size()-1][0],dp[v.size()-1][1])+n+1);
    return min(dp[v.size()-1][0],dp[v.size()-1][1])+n+1<=t;
}

int main()
{
    scanf("%d%d%d%d",&m,&n,&k,&t);
    for(int i=0;i<m;i++) scanf("%d",a+i);
    for(int i=0;i<k;i++)
        scanf("%d%d%d",&p[i].L,&p[i].R,&p[i].D);
    sort(p,p+k,cmp);
    int mid,l=0,r=200001;
    while(l<r)
    {
        mid=l+r>>1;
        if(check(mid)) r=mid; else l=mid+1;
    }
    int ans=0;
    for(int i=0;i<m;i++) if(a[i]>=l) ans++;
    printf("%d",ans);
    return 0;
}
