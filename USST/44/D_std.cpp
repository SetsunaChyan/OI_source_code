#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000004;
int X[1000005],Y[1000005],op,n;
struct node
{
    int x1,x2,y1,y2;
};
stack<node> s;

inline int lowbit(int x){return x&-x;}

void bit_add(int bit[],int x,int y)
{
    for(;x<=MAXN;x+=lowbit(x)) bit[x]+=y;
}

int bit_sum(int bit[],int x)
{
    int ret=0;
    for(;x>0;x-=lowbit(x)) ret+=bit[x];
    return ret;
}

int main()
{
    memset(X,0,sizeof(X));
    memset(Y,0,sizeof(Y));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int q;
        scanf("%d",&op);
        if(op==1)
        {
            node e;
            scanf("%d%d%d%d",&e.x1,&e.y1,&e.x2,&e.y2);
            s.push(e);
            bit_add(X,min(e.x1,e.x2),1);
            bit_add(X,max(e.x1,e.x2)+1,-1);
            bit_add(Y,min(e.y1,e.y2),1);
            bit_add(Y,max(e.y1,e.y2)+1,-1);
        }
        else if(op==4)
        {
            if(s.empty()) continue;
            node e=s.top();
            s.pop();
            bit_add(X,min(e.x1,e.x2),-1);
            bit_add(X,max(e.x1,e.x2)+1,1);
            bit_add(Y,min(e.y1,e.y2),-1);
            bit_add(Y,max(e.y1,e.y2)+1,1);
        }
        else if(op==2)
        {
            scanf("%d",&q);
            printf("%d\n",bit_sum(X,q));
        }
        else if(op==3)
        {
            scanf("%d",&q);
            printf("%d\n",bit_sum(Y,q));
        }
    }
    return 0;
}