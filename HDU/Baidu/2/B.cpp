#include <bits/stdc++.h>
using namespace std;

char s1[25][100],s2[25][100];
int n,m,flag,ans[100],used[100];

void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s%s",s1[i],s2[i]);
    flag=0;
    memset(used,0,sizeof(used));
    for(int j=0;j<m;j++)
        for(int k=0;k<m;k++)
            if(!used[k])
            {
                int qaq=1;
                for(int i=0;i<n;i++)
                    if(s1[i][j]!=s2[i][k])
                    {
                        qaq=0;
                        break;
                    }
                if(!qaq) continue;
                flag++;
                ans[j]=k;
                used[k]=1;
                break;
            }
    if(flag==m) for(int i=0;i<m;i++) printf("%d%c",ans[i]+1," \n"[i==m-1]);
    else printf("-1\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
