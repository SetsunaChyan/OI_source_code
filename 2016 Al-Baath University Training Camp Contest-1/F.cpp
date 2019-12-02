#include <bits/stdc++.h>
using namespace std;

string a,b;

void solve()
{
    cin>>a>>b;
    int f1=0,f2=0;
    for(int i=0;i<a.size()-2;i++)
    {
        if(i<a.size()-3&&a.substr(i,4)==b) f1=1;
        if(a[i]==b[0]&&a[i+1]==b[1]&&a[i+2]==b[2]) f2=1;
        if(a[i]==b[0]&&a[i+1]==b[2]&&a[i+2]==b[3]) f2=1;
        if(a[i]==b[0]&&a[i+1]==b[1]&&a[i+2]==b[3]) f2=1;
        if(a[i]==b[1]&&a[i+1]==b[2]&&a[i+2]==b[3]) f2=1;
    }
    if(f1) printf("good\n");
    else if(f2) printf("almost good\n");
    else printf("none\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

