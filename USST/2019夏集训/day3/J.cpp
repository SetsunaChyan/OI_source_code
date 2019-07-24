#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pre[5005],ans=0;
int n;
char s[5005];

int main()
{
    memset(pre,0,sizeof(pre));
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++)
        if(s[i]=='A')
            for(int j=0;j<=i-2;j++)
                if(s[j]=='Q') pre[i]++;
    for(int i=0;i<n;i++)
        if(s[i]=='Q')
            for(int j=0;j<=i-2;j++)
                if(s[j]=='A') ans+=pre[j];
    printf("%lld\n",ans);
    return 0;
}
