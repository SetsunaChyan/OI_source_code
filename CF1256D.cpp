#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;
int n;
char s[1000005];

void solve()
{
    queue<int> q;
    scanf("%d%lld%s",&n,&k,s);
    for(int i=0;i<n;i++)
        if(s[i]=='0') q.push(i);
    for(int i=0;i<n;i++)
    {
        if(q.empty()) break;
        if(s[i]=='0')
        {
            q.pop();
            continue;
        }
        if(q.front()-i<=k)
        {
            s[q.front()]='1';
            s[i]='0';
            k-=q.front()-i;
            q.pop();
        }
        else break;
    }
    if(!q.empty())
        for(int i=q.front();i>0&&k;i--,k--)
            swap(s[i-1],s[i]);
    for(int i=0;i<n;i++) printf("%c",s[i]);
    printf("\n");
    //printf("%s\n",s);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
