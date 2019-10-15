#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,a[5005],dp[5005],mx,b[5005];
vector<int> v;
vector<pii> p;

bool cmp(pii a,pii b)
{
    return a.second-a.first<b.second-b.first;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    v.push_back(a[0]);
    for(int i=1;i<n;i++)
        if(a[i]!=a[i-1]) v.push_back(a[i]);
    for(int i=1;i<=5000;i++)
    {
        int l=0,r=v.size()-1;
        while(l<r)
        {
            while(l<v.size()&&v[l]!=i) l++;
            while(r>=0&&v[r]!=i) r--;
            if(l<r) b[l]++,b[r+1]--,l++,r--;
        }
    }
    for(int i=1;i<v.size();i++) b[i]+=b[i-1];
    for(int i=0;i<v.size();i++)
    {
        dp[i]=(b[i]!=0);
        for(int j=0;j<i;j++)
            if(b[j]<b[i]) dp[i]=max(dp[i],dp[j]+1);
        mx=max(mx,dp[i]);
    }
    printf("%d",v.size()-mx-1);
    return 0;
}

/*
9
5 4 3 2 1 2 3 4 5
*/
