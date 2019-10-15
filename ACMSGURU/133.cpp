#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

#define l first
#define r second
int n,bit[35000],ans;
vector<int> v;
pii p[16005];

int sum(int x)
{
    int ret=0;
    for(;x;x-=x&-x) ret+=bit[x];
    return ret;
}

void add(int x)
{
    for(;x<=2*n;x+=x&-x) bit[x]++;
}

int main()
{
    scanf("%d",&n);
    for(int i=0,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        p[i]={x,y};
        v.push_back(x),v.push_back(y);
    }
    sort(v.begin(),v.end());
    sort(p,p+n);
    for(int i=0;i<n;i++)
    {
        p[i].l=lower_bound(v.begin(),v.end(),p[i].l)-v.begin()+1;
        p[i].r=lower_bound(v.begin(),v.end(),p[i].r)-v.begin()+1;
    }
    for(int i=0;i<n;i++)
    {
        if(sum(2*n)-sum(p[i].r)) ans++;
        add(p[i].r);
    }
    printf("%d",ans);
    return 0;
}
