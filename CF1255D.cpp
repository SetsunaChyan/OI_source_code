#include <bits/stdc++.h>
using namespace std;

char tab[100]="1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int n,m,k,cur,r,now;
char s[105][105],ans[105][105];
vector<int> qaq;

void solve()
{
    qaq.clear();r=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='R') r++;
            ans[i][j]=0;
        }
    for(int i=0;i<k;i++) qaq.push_back(r/k);
    for(int i=0;i<r%k;i++) qaq[i]++;
    cur=0;now=0;
    for(int i=0;i<n;i++)
    {
        if(i&1)
            for(int j=m-1;j>=0;j--)
            {
                ans[i][j]=tab[cur];
                if(s[i][j]=='R') now++;
                if(now>=qaq[cur]) cur++,now=0;
                if(cur>=k) cur--;
            }
        else
            for(int j=0;j<m;j++)
            {
                ans[i][j]=tab[cur];
                if(s[i][j]=='R') now++;
                if(now>=qaq[cur]) cur++,now=0;
                if(cur>=k) cur--;
            }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(ans[i][j]==0) ans[i][j]=tab[k-1];
    for(int i=0;i<n;i++)
        for(int j=0;j<=m;j++)
            printf("%c",j==m?'\n':ans[i][j]);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
