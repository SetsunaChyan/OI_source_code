#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,q,bit[26][100005],op,pos,r;
char s[100005],c;

void add(int bits[],int x,int y)
{
    for(;x<=n;x+=x&-x) bits[x]+=y;
}

int sum(int bits[],int x)
{
    int ret=0;
    for(;x;x-=x&-x) ret+=bits[x];
    return ret;
}

int main()
{
    scanf("%s%d",s+1,&q);
    n=strlen(s+1);
    for(int i=1;i<=n;i++) add(bit[s[i]-'a'],i,1);
    while(q--)
    {
        scanf("%d%d",&op,&pos);
        if(op==1)
        {
            scanf(" %c",&c);
            add(bit[s[pos]-'a'],pos,-1);
            s[pos]=c;
            add(bit[c-'a'],pos,1);
        }
        else
        {
            scanf("%d",&r);
            int ret=0;
            for(int i=0;i<26;i++) if(sum(bit[i],r)-sum(bit[i],pos-1)) ret++;
            printf("%d\n",ret);
        }
    }
    return 0;
}

