#include <bits/stdc++.h>
using namespace std;

int cnt[200005][26],len,m,g[26];
char s[200005],t[200005];

bool check(int x)
{
    for(int i=0;i<26;i++)
        if(g[i]>cnt[x][i]) return false;
    return true;
}

int main()
{
    memset(cnt,0,sizeof(cnt));
    scanf("%d%s",&len,s);
    cnt[0][s[0]-'a']=1;
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<26;j++) cnt[i][j]=cnt[i-1][j];
        cnt[i][s[i]-'a']++;
    }
    scanf("%d",&m);
    while(m--)
    {
        int l=0,r=len,n;
        scanf("%s",t);
        n=strlen(t);
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++)
            g[t[i]-'a']++;
        while(l<r)
        {
            int m=l+r>>1;
            if(check(m)) r=m; else l=m+1;
        }
        printf("%d\n",l+1);
    }

    return 0;
}
