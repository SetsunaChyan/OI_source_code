#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,k,big[10005],see,x,ans;
char s[5];

void gao()
{
    ans=0;
    scanf("%d%d%d",&n,&m,&k);
    see=k;
    for(int i=1;i<=n;i++)
        scanf("%s",s),big[i]=(s[0]=='B');
    while(m--)
    {
        scanf("%s",s);
        if(s[0]=='A')
        {
            see=n;
            continue;
        }
        scanf("%d",&x);
        if(x<=see&&!big[x]) ans++;
        see=max(see,x);
    }
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) gao();
    return 0;
}
