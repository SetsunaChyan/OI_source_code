#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[100005],t[100005];
vector<int>v;
int main()
{
    int _,n;scanf("%d",&_);
    while(_--)
    {
        v.clear();
        scanf("%d%s%s",&n,s,t);
        for(int i=0;i<n;i++)if(s[i]!=t[i])v.push_back(i);
        if(v.empty())
        {
            printf("YES\n");
            continue;
        }
        char c=t[v.back()];
        for(int i=v.size()-2;i>=0;i--)
            t[v[i+1]]=t[v[i]];
        t[v[0]]=c;
        //puts(t);
        puts(strcmp(s,t)?"NO":"YES");
    }
    return 0;
}
