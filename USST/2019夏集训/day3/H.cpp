#include <bits/stdc++.h>
using namespace std;

int ans=0,n,nxt[2000005][2],tot=1,val[2000005],dep[2000005];
char s[205];

void trie_insert(char s[],int l)
{
    int p=1;
    for(int i=0;i<l;i++)
    {
        int c=s[i]-'0';
        if(!nxt[p][c])
        {
            nxt[p][c]=++tot;
            val[nxt[p][c]]=0;
            dep[nxt[p][c]]=dep[p]+1;
        }
        p=nxt[p][c];
        val[p]++;
        ans=max(ans,dep[p]*val[p]);
    }
}

int main()
{
    scanf("%d",&n);
    dep[1]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        trie_insert(s,strlen(s));
    }
    printf("%d",ans);
    return 0;
}
