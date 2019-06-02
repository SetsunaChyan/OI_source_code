#include <bits/stdc++.h>
using namespace std;

int p[100],n,pos[100],x;
stack<int> s;

bool test(int x)
{
    while(!s.empty()) s.pop();
    memset(p,0,sizeof(p));
    for(int i=x;i<n;i+=2)
        p[pos[i]]=p[pos[i+1]]=i;
    for(int i=1;i<=n;i++)
        if(p[i])
            if(!s.empty()&&s.top()==p[i]) s.pop(); else s.push(p[i]);
    if(s.empty()) return true;
    return false;
}

void solve()
{
    while(!s.empty()) s.pop();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&x),pos[x]=i;
    if(test(1)&&test(2))
        printf("yes\n");
    else 
        printf("no\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}