#include <bits/stdc++.h>
using namespace std;
struct node
{
    string x,y;
    int p;
}b[100005];
string xs[5],ys;
vector<int>v[12];
vector<pair<int,string>>vv[2];
int n,ans,a[12];
void dfs(int k,int s)
{
    if(k==10)
    {
        int t=0,c1=0,c2=0;
        for(int i=0;i<k;i++)
        {
            if(i<=4)c1+=a[i],c2+=a[i];
            else c1+=a[i];
            for(int j=0;j<a[i];j++)
                t+=v[i][j];
        }
        for(int msk=0;msk<(1<<5);msk++)
        {
            set<string>ss;
            int col=0,tt=0;
            int nd;
            for(int i=0;i<5;i++)
                if((msk>>i)&1)
                {
                    if(i>=vv[0].size())
                        goto fail;
                    ss.insert(vv[0][i].second);
                    ++col;
                    tt+=vv[0][i].first;
                }
            nd=5-s-col;
            if(nd<0)goto fail;
            for(int i=0;i<min(5,(int)vv[1].size())&&nd;i++)
                if(ss.find(vv[1][i].second)==ss.end())
                {
                    --nd;
                    tt+=vv[1][i].first;
                }
            if(nd)goto fail;
            ans=max(ans,(t+tt)*(10+2*(c2+col)+c1)/10);
            fail:;
        }
        return;
    }
    a[k]=0,dfs(k+1,s);
    if(v[k].size()&&(k<=4||k>=5&&!a[k-5]))
        a[k]=1,dfs(k+1,s+1),a[k]=0;
}
map<string,int>h;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--)
    {
        ans=0;
        for(int i=0;i<10;i++)v[i].clear();
        vv[0].clear();
        vv[1].clear();
        cin>>n;
        for(int i=1;i<=n;i++)cin>>b[i].x>>b[i].y>>b[i].p;
        for(int i=0;i<5;i++)cin>>xs[i];cin>>ys;
        h.clear();
        for(int i=1,j;i<=n;i++)if(b[i].y==ys)
        {
            for(j=0;j<5;j++)if(b[i].x==xs[j]){v[j].push_back(b[i].p);break;}
            if(j==5)
                h[b[i].x]=max(h[b[i].x],b[i].p);
        }
        for(auto p:h)
            vv[0].emplace_back(p.second,p.first);
        h.clear();
        for(int i=1,j;i<=n;i++)if(b[i].y!=ys)
        {
            for(j=0;j<5;j++)if(b[i].x==xs[j]){v[j+5].push_back(b[i].p);break;}
            if(j==5)
                h[b[i].x]=max(h[b[i].x],b[i].p);
        }
        for(auto p:h)
            vv[1].emplace_back(p.second,p.first);
        for(int i=0;i<10;i++)sort(begin(v[i]),end(v[i]),greater<int>());
        sort(begin(vv[0]),end(vv[0]),greater<pair<int,string>>());
        sort(begin(vv[1]),end(vv[1]),greater<pair<int,string>>());
        dfs(0,0);
        cout<<ans<<'\n';
    }
    return 0;
}
