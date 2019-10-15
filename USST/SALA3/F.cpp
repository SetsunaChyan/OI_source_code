#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
set<pair<int,int>> check;
int cur[200005];

int main()
{
    scanf("%lld%lld",&n,&k);
    if(k*(k-1)<n) return printf("NO"),0;
    printf("YES\n");
    for(int i=1;i<=k;i++) cur[i]=i+1;
    cur[k]=1;
    int now=1,tmp;
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n",now,cur[now]);
        tmp=cur[now];
        //if(check.find({now,tmp})!=check.end()) printf("!\n");
        //check.emplace(now,tmp);
        do
        {
            cur[now]++;
            if(cur[now]>k) cur[now]=1;
        }while(cur[now]==now);
        now=tmp;
    }
    return 0;
}
