#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const char T[11][36]={
"xxxxxx...xx...xx...xx...xx...xxxxxx",
"....x....x....x....x....x....x....x",
"xxxxx....x....xxxxxxx....x....xxxxx",
"xxxxx....x....xxxxxx....x....xxxxxx",
"x...xx...xx...xxxxxx....x....x....x",
"xxxxxx....x....xxxxx....x....xxxxxx",
"xxxxxx....x....xxxxxx...xx...xxxxxx",
"xxxxx....x....x....x....x....x....x",
"xxxxxx...xx...xxxxxxx...xx...xxxxxx",
"xxxxxx...xx...xxxxxx....x....xxxxxx",
".......x....x..xxxxx..x....x......."
};
int cur;
char s[7][1000],p[1000],ans[7][1000];
vector<int> v;

void gao(int x)
{
    for(int tp=0;tp<11;tp++)
    {
        int flag=1;
        for(int i=0;i<7;i++)
            for(int j=x;j<x+5;j++)
                if(s[i][j]!=T[tp][i*5+j-x]) flag=0;
        if(flag)
        {
            if(tp!=10) p[cur++]=tp+'0'; else p[cur++]='+';
            return;
        }
    }
}

void igao(int x,int y)
{
    for(int i=0;i<7;i++)
        for(int j=x;j<x+5;j++)
            ans[i][j]=T[y][i*5+j-x];
}

int main()
{
    for(int i=0;i<7;i++)
        scanf("%s",s[i]);
    int n=strlen(s[0]);
    for(int i=0;i<n;i+=6) gao(i);
    ll a,b;
    sscanf(p,"%lld+%lld",&a,&b);
    a=a+b;
    while(a)
    {
        v.push_back(a%10);
        a/=10;
    }
    reverse(v.begin(),v.end());
    cur=0;
    memset(ans,'.',sizeof(ans));
    for(auto a:v)
        igao(cur*6,a),cur++;
    for(int i=0;i<7;i++) ans[i][v.size()*6-1]=0;
    for(int i=0;i<7;i++) printf("%s\n",ans[i]);
    return 0;
}
