#include <bits/stdc++.h>
using namespace std;

/*
    ������������kС
    �õ�ʱ��ע���¿ռ� ʱ�� O(nlog^2(n))
    ��� add(pos,x,y) �ռ���Ϊpos�ĵ���ֵ����Ϊx�ĵ����y
         query(l,r,k) ѯ������[l,r]��kС
    �ڲ� modify ֵ���߶�����̬����
         query ֵ���߶�������kС
    VAL ֵ���С
*/

const int MAXN=200005;
int n,a[MAXN],X[MAXN],Y[MAXN],c1,c2,VAL;
struct SEG
{
    int root[MAXN],lc[MAXN*500],rc[MAXN*500],cnt[MAXN*500],tot;
    void modify(int &rt,int l,int r,int x,int y)
    {
        if(rt==0) rt=++tot;
        cnt[rt]+=y;
        if(l==r) return;
        int m=l+r>>1;
        if(x<=m) modify(lc[rt],l,m,x,y);
        else modify(rc[rt],m+1,r,x,y);
    }
    int query(int l,int r,int k)
    {
        if(l==r) return l;
        int sum=0,m=l+r>>1;
        for(int i=0;i<c1;i++) sum-=cnt[lc[X[i]]];
        for(int i=0;i<c2;i++) sum+=cnt[lc[Y[i]]];
        if(sum>=k)
        {
            for(int i=0;i<c1;i++) X[i]=lc[X[i]];
            for(int i=0;i<c2;i++) Y[i]=lc[Y[i]];
            return query(l,m,k);
        }
        else
        {
            for(int i=0;i<c1;i++) X[i]=rc[X[i]];
            for(int i=0;i<c2;i++) Y[i]=rc[Y[i]];
            return query(m+1,r,k-sum);
        }
    }
}seg;

void add(int pos,int x,int y)
{
    for(;pos<=n;pos+=pos&-pos) seg.modify(seg.root[pos],1,VAL,x,y);
}

int query(int l,int r,int k)
{
    c1=c2=0;
    for(int i=l-1;i;i-=i&-i) X[c1++]=seg.root[i];
    for(int i=r;i;i-=i&-i) Y[c2++]=seg.root[i];
    return seg.query(1,VAL,k);
}

int main()
{

    return 0;
}
