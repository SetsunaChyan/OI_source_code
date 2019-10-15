#include <bits/stdc++.h>
using namespace std;
typedef pair<int,string> pis;

int n;
pis p[105];
string s;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>s;
        p[i]=make_pair(0,s);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            if(p[i].second.find(p[j].second,0)!=string::npos) p[i].first++;
        }
    sort(p,p+n);
    for(int i=1;i<n;i++)
        if(p[i].second.find(p[i-1].second,0)==string::npos)
        {
            printf("NO");
            return 0;
        }
    printf("YES\n");
    for(int i=0;i<n;i++)
        cout<<p[i].second<<endl;
    return 0;
}
