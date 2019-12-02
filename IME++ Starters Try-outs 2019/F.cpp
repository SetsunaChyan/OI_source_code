#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,op,fa[100005];
map<string,int> mp;
char s[15],t[15];

int _find(int x){return fa[x]==x?x:fa[x]=_find(fa[x]);}
void _merge(int x,int y){fa[_find(x)]=_find(y);}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s),mp[string(s)]=i,fa[i]=i;
    while(m--)
    {
        scanf("%d%s%s",&op,s,t);
        if(op==1) _merge(mp[string(s)],mp[string(t)]);
        else if(_find(mp[string(s)])==_find(mp[string(t)])) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
