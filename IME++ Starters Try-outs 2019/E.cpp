#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int nxt[8100005][26];
bool vis[8100005];
char t[8100005],ans[8100005*2];

int main()
{
    register int n,cur=0,cnt=0,p,c,tot=1;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    ans[cur++]='\n';
    while(n--)
    {
        cin>>t;
        p=1;
        for(register int i=0;t[i];i++)
        {
            if(!nxt[p][t[i]-'a']) nxt[p][t[i]-'a']=++tot;
            p=nxt[p][t[i]-'a'];
        }
        if(vis[p]&&strlen(t)>3)
        {
            cnt++;
            for(register int i=0;t[i];i++) ans[cur++]=t[i];
            ans[cur++]='\n';
        }
        vis[p]=1;
    }
    if(cnt==0) cout<<"SAFO";
    else cout<<cnt<<ans;
    return 0;
}
