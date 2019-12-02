#include <bits/stdc++.h>
using namespace std;

int n,val;
string s;
struct node
{
    int siz;
    node(){siz=0;}
    string str;
    map<string,node> e;
}root;

void dfs(node &p,string pre)
{
    int flag=0;
    for(auto son:p.e)
        if(son.second.siz>=val) flag=1;
    if(flag)
    {
        if(p.e.size())
            cout<<"- "<<pre<<p.str<<" "<<p.siz<<"\n";
        else
            cout<<"  "<<pre<<p.str<<" "<<p.siz<<"\n";
        for(auto to:p.e) dfs(to.second,pre+p.str);
    }
    else
        if(p.e.size())
            cout<<"+ "<<pre<<p.str<<" "<<p.siz<<"\n";
        else
            cout<<"  "<<pre<<p.str<<" "<<p.siz<<"\n";
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int last=1,w;
        node *p=&root,*q;
        cin>>s>>w;
        for(int j=1;j<s.size();j++)
            if(s[j]=='/')
            {
                string pre=s.substr(last,j-last)+"/";
                //cout<<pre<<"\n";
                q=&(p->e[pre]);
                q->str=pre;
                p->siz+=w;
                p=q;
                last=j+1;
            }
        p->siz+=w;
    }
    cin>>val;
    dfs(root,string("/"));
    return 0;
}
