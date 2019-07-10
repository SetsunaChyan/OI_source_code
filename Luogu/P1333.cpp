#include <bits/stdc++.h>
using namespace std;

int tot=0,deg[500000],fa[500000];
map<string,int> m;
string sa,sb;
char a[15],b[15];

int _find(int x){return fa[x]==x?x:fa[x]=_find(fa[x]);}
void _union(int x,int y){fa[_find(x)]=_find(y);}

int main()
{
    memset(deg,0,sizeof(deg));
    for(int i=0;i<500000;i++) fa[i]=i;
    while(~scanf("%s%s",a,b))
    {
        sa=string(a),sb=string(b);
        if(m.find(sa)==m.end()) m[sa]=tot++;
        if(m.find(sb)==m.end()) m[sb]=tot++;
        int x=m[sa],y=m[sb];
        deg[x]++,deg[y]++;
        if(_find(x)!=_find(y)) _union(x,y);
    }
    int qaq=0;
    for(int i=0;i<tot;i++)
        if(_find(i)!=_find(0))
        {
            printf("Impossible");
            return 0;
        }
    for(int i=0;i<tot;i++)
        if(deg[i]&1) qaq++;
    if(qaq<=2) printf("Possible"); else printf("Impossible");
    return 0;
}
