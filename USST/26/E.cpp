#include <cstdio>
#include <cstring>
#include <string>
#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;

int n,tmp,vis[1005],tot=0;
char s[100];
string p[1005];

int main()
{
    memset(vis,0,sizeof(vis));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(!vis[x])
        {
            vis[x]++;
            sprintf(s,"%d",x);
            p[tot++]=string(s);
        }
    }
    sort(p,p+tot);
    for(int i=0;i<tot;i++)
        cout<<p[i]<<" ";
    return 0;
}  
