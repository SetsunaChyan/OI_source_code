#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int mv[8][2]={0,1,1,0,0,-1,-1,0,1,1,1,-1,-1,1,-1,-1};
map<pii,int> m;
vector<pii> ins,del;
int mx,mxn;
char s[10][10];

bool check(int x,int y)
{
    int k=0,flag=0;
    if(m.find(make_pair(x,y))!=m.end()) flag=1;
    for(int j=0;j<8;j++)
        if(m.find(make_pair(x+mv[j][0],y+mv[j][1]))!=m.end()) k++;
    if(flag)
    {
        if(k<2||k>3) return false;
        return true;
    }
    else
    {
        if(k==3) return true;
        return false;
    }
}

void solve(int x)
{
    m.clear();
    mxn=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<5;j++)
        {
            int k=i*5+j;
            if(x&(1<<k)) m[make_pair(i,j)]=1;
        }
    mx=m.size();
    for(int i=1;i<=321;i++)
    {
        ins.clear();
        del.clear();
        for(auto pp:m)
        {
            pii p=pp.first;
            for(int j=0;j<8;j++)
                if(check(p.first+mv[j][0],p.second+mv[j][1]))
                    ins.emplace_back(p.first+mv[j][0],p.second+mv[j][1]);
            if(!check(p.first,p.second)) del.push_back(p);
        }
        for(auto p:del) m.erase(p);
        for(auto p:ins) m[p]=1;
        if(m.size()>mx)
            mx=m.size(),mxn=i;
    }
    printf("{%d,%d,%d},",mxn,mx,m.size());
}


int main()
{
    /*memset(s,0,sizeof(s));
    int n,m;
    scanf("%d%d",&n,&m);
    int k=0;
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<3;i++)
        for(int j=0;j<5;j++)
        {
            k<<=1;
            if(s[i][j]=='#') k++;
        }*/

    freopen("biao.txt","w",stdout);
    for(int i=0;i<(1<<15);i++)
        solve(i);
    return 0;
}
