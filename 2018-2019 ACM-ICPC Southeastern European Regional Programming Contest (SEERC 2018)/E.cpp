#include <bits/stdc++.h>
using namespace std;
int read()
{
    int x=0;char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=getchar();
    return x;
}
void print(int x)
{
    static char c[12];
    int l=0;
    if(!x)puts("0");
    else
    {
        while(x)c[l++]=x%10+'0',x/=10;
        while(l--)putchar(c[l]);
        putchar('\n');
    }
}
int n,m,l,L[200005],R[200005],x[200005],pre[600005];
vector<int> v;

int main()
{
	scanf("%d%d%d",&n,&m,&l);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",L+i,R+i);
		if(R[i]<=l) v.push_back(L[i]-(l-R[i])),v.push_back(L[i]+(l-R[i])+1);
	}
	for(int i=0;i<m;i++)
    {
        scanf("%d",x+i);
        v.push_back(x[i]);
    }
    sort(v.begin(),v.end());
    for(int i=0,k;i<n;i++)
    {
        if(R[i]>l) continue;
        k=lower_bound(v.begin(),v.end(),L[i]-(l-R[i]))-v.begin();
        pre[k]++;
        k=lower_bound(v.begin(),v.end(),L[i]+(l-R[i])+1)-v.begin();
        pre[k]--;
    }
    for(int i=1;i<v.size();i++) pre[i]+=pre[i-1];
	for(int i=0,k;i<m;i++)
    {
        k=lower_bound(v.begin(),v.end(),x[i])-v.begin();
		printf("%d\n",pre[k]);
    }
	return 0;
}

/*
8 4 4
7 2
3 3
4 5
5 1
2 2
1 4
8 4
9 4
6 1 4 9
*/
