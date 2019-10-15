#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,x,flag,last,sum,dep=-1,tmp;
unordered_map<int,int> mp;
vector<pii> v;

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        tmp=x;
        if(x<=dep||mp[0]>0)
        {
            printf("No\n");
            continue;
        }
        v.clear();
        flag=0;
        v.emplace_back(x,mp[x]);
        last=sum;
        mp[x]++,last++;
        while(mp[x]>1)
        {
            v.emplace_back(x-1,mp[x-1]);
            last--;
            mp[x-1]+=mp[x]/2;mp[x]%=2;
            //printf("QAQ %d %d\n",x,mp[x]);
            x--;
            if(x==0&&mp[0]>0&&last>1)
            {
                flag=1;
                dep=max(dep,tmp);
                printf("No\n");
                break;
            }
        }
        if(flag) for(auto &p:v) mp[p.first]=p.second;
        else sum=last,printf("Yes\n");
    }
    return 0;
}
