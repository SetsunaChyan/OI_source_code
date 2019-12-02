#include <bits/stdc++.h>
using namespace std;

int w,h,flag;
vector<pair<int,int>> ans;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&h,&w);
    if(h%2==w%2&&h>w)
        swap(w,h),flag=1;
    else if(h%2==0&&w%2==1)
        swap(w,h),flag=1;
    if(w&1) for(int i=2;i<h;i+=2) ans.emplace_back(i-1,1);
    for(int j=2+(w&1);j<=w;j+=2)
    {
        for(int i=1;i<h;i++)
            ans.emplace_back(i,j-1);
        if(j<w&&h!=1) ans.emplace_back(h-1,j);
    }
    printf("%d\n",(int)ans.size());
    for(auto p:ans)
        if(flag) printf("%d %d\n",p.second,p.first);
        else printf("%d %d\n",p.first,p.second);
    return 0;
}
