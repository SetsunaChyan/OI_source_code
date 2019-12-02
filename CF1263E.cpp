#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,N,mm[1000005<<2],mx[1000005<<2],lazy[1000005<<2],z,y;
char s[1000005],g[1000005];

inline void pushdown(int rt)
{
    int &x=lazy[rt];
    mm[rt<<1]+=x;mm[rt<<1|1]+=x;
    mx[rt<<1]+=x;mx[rt<<1|1]+=x;
    lazy[rt<<1]+=x;lazy[rt<<1|1]+=x;
    x=0;
}

void modify(int rt,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {
        mm[rt]+=x;
        mx[rt]+=x;
        lazy[rt]+=x;
        return;
    }
    if(lazy[rt]) pushdown(rt);
    int m=l+r>>1;
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(m<R) modify(rt<<1|1,m+1,r,L,R,x);
    mm[rt]=min(mm[rt<<1],mm[rt<<1|1]);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}

int query(int rt,int l,int r,int x)
{
    if(l==r) return mx[rt];
    if(lazy[rt]) pushdown(rt);
    int m=l+r>>1,ret;
    if(x<=m) ret=query(rt<<1,l,m,x);
    else ret=query(rt<<1|1,m+1,r,x);
    mm[rt]=min(mm[rt<<1],mm[rt<<1|1]);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
    return ret;
}

int main()
{
    scanf("%d%s",&n,s);
    int cur=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R') cur++;
        else if(s[i]=='L') cur=cur>1?cur-1:cur;
        if(s[i]==')'||s[i]=='(') N=max(N,cur);
    }
    N++;cur=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R') cur++;
        else if(s[i]=='L') cur=cur>1?cur-1:cur;
        else
        {
            if(g[cur]==')'&&s[i]=='(') // )-->(
                modify(1,1,N,cur,N,2),y--,z++;
            else if(g[cur]=='('&&s[i]==')') // (-->)
                modify(1,1,N,cur,N,-2),y++,z--;
            else if(g[cur]==')'&&s[i]!='('&&s[i]!=')') // )-->x
                modify(1,1,N,cur,N,1),y--;
            else if(g[cur]=='('&&s[i]!='('&&s[i]!=')') // (-->x
                modify(1,1,N,cur,N,-1),z--;
            else if(g[cur]!='('&&g[cur]!=')'&&s[i]==')') // x-->)
                modify(1,1,N,cur,N,-1),y++;
            else if(g[cur]!='('&&g[cur]!=')'&&s[i]=='(') // x-->(
                modify(1,1,N,cur,N,1),z++;
            g[cur]=s[i];
        }
        //printf("! %d %d %d\n",cur,mm[1],mx[1]);
        if(mm[1]==0&&z==y) printf("%d ",mx[1]);
        else printf("-1 ");
    }
    return 0;
}
