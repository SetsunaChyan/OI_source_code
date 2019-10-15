#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
map<string,string> qaq;
string a,b;
char s[1000];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        qaq[b]=a;
    }
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        for(int j=0;j<b.size();j++)
            s[j]=b[j];
        s[b.size()-1]=0;
        cout<<a<<" "<<b<<" #"<<qaq[string(s)]<<endl;
    }
    return 0;
}
