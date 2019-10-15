#include <bits/stdc++.h>
using namespace std;

int a,b,qaq,l,QAQ;
vector<int> gao;
char s[300005];

int cal(int x)
{
    int flag=1;
    if(x<a) return 0;
    if(x-a<=2*b-2) flag=0;
    return flag^(a>=b);
}

void solve()
{
    gao.clear();
    scanf("%d%d%s",&a,&b,s);
    QAQ=qaq=0;l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(s[i]=='.') qaq++;
        else if(qaq)
        {
            gao.push_back(qaq);
            qaq=0;
        }
    }
    if(qaq) gao.push_back(qaq);
    for(auto q:gao)
        if(q<a&&q<b) continue; else QAQ^=cal(q);
    if(QAQ) printf("YES\n"); else printf("NO\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
