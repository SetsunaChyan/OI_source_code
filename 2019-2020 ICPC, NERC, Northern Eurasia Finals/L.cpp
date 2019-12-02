#include <bits/stdc++.h>
using namespace std;
int k,n,l,h[26];
bool ls[1003];
char s[1000006],ans[1003][1003];
int main()
{
    scanf("%d%d%d%s",&n,&l,&k,s);
    for(int i=0;s[i];i++)
        h[s[i]-'a']++;
    for(int i=0;i<l;i++)
        for(int o=n;o>k;o--)
            for(int p=25;p>=0;p--)if(h[p]){--h[p];ans[o][i]='a'+p;break;}
    for(int o=1;o<=k;o++)
            for(int p=0;p<26;p++)if(h[p]){--h[p];ans[o][0]='a'+p;break;}
    for(int i=1;i<l;i++)
    {
        for(int j=1;j<k;j++)
            if(ans[j][i-1]<ans[k][i-1])
                ls[j]=1;
        for(int o=1;o<=k;o++)
        {
            if(!ls[o])
            {
                for(int p=0;p<26;p++)if(h[p]){--h[p];ans[o][i]='a'+p;break;}
            }
            else
                for(int p=25;p>=0;p--)if(h[p]){--h[p];ans[o][i]='a'+p;break;}
        }
    }
    vector<string>v;
    v.resize(n);
    for(int i=1;i<=n;i++)
        for(int j=0;j<l;j++)
            v[i-1]+=ans[i][j];
    sort(begin(v),end(v));
    for(auto vv:v)
        puts(vv.data());
    return 0;
}
