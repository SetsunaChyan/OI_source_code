#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,p,q,m,cur,mx,a[6000005];
ll ans;
stack<int> st;
unsigned int SA,SB,SC;
unsigned int rng61()
{
    SA^=SA<<16;
    SA^=SA>>5;
    SA^=SA<<1;
    unsigned int t=SA;SA=SB;
    SB=SC;
    SC^=t^SA;
    return SC;
}

void PUSH(int x)
{
    if(!st.empty()&&a[st.top()]<x) st.push(cur);
    else if(st.empty()) st.push(cur);
    a[cur++]=x;
}

void POP()
{
    if(cur) cur--;
    while(!st.empty()&&st.top()>=cur) st.pop();
}

void solve(int cs)
{
    while(!st.empty()) st.pop();
    ans=cur=0;
    scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
    for(int i=1;i<=n;i++)
    {
        if(rng61()%(p+q)<p)
            PUSH(rng61()%m+1);
        else
            POP();
        if(!st.empty())
            ans^=(long long)i*a[st.top()];
    }
    printf("Case #%d: %lld\n",cs,ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int i=1;i<=_;i++) solve(i);
    return 0;
}
