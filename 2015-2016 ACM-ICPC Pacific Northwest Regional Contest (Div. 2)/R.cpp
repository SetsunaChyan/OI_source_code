#include <bits/stdc++.h>
using namespace std;
typedef pair<string,string> pss;

int n;
pss p[105];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a,b;
        cin>>a>>b;
        p[i]={b,a};
    }
    sort(p,p+n);
    for(int i=0;i<n;i++)
        cout<<p[i].second<<" "<<p[i].first<<endl;
    return 0;
}
