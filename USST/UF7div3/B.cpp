#include <bits/stdc++.h>
using namespace std;

int flag,cnt,n,k,qaq;
vector<int> a;

bool check()
{
    sort(a.begin(),a.end());
    if(a[(a.size()-1)/2]==k) return true;
    return false;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0,x;i<n;i++)
    {
        scanf("%d",&x);
        a.push_back(x);
        if(x==k) flag=1;
    }
    if(!flag) cnt++,a.push_back(k);
    while(!check())
    {
        cnt++;
        a.push_back(k);
    }
    printf("%d",cnt);
    return 0;
}
