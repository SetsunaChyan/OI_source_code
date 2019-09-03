#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
const int N=1000000+20;
int M,n,m,tree[N<<2];
void pushup(int i)//���ϸ���
{
	tree[i]=max(tree[i<<1],tree[i<<1|1]);
}
void update(int x,int v)//�����޸ģ���x��ֵ���v
{
	for(tree[x+=M]=v,x>>=1; x; x>>=1)
		pushup(x);
}
int query(int l,int r)//��[l~r]�����ֵ
{
	int ans=0;
	//l^r^1�ж��Ƿ����ֵܽڵ㣬>0ʱ���ֵܽڵ�
	//���ֵ����˳�ѭ��
	for(l=l+M-1,r=r+M+1; l^r^1; l>>=1,r>>=1)
	{
		//l&1^1,r&1�ֱ��ж�ż��������
		if(l&1^1) ans=max(ans,tree[l^1]);//l+1
		if(r&1)   ans=max(ans,tree[r^1]);//r-1
	}
	return ans;
}
void build()
{
	for(M=1; M<n; M<<=1);
	for(int i=M+1; i<=M+n; i++)
		scanf("%d",&tree[i]);
	for(int i=M; i>=1; i--)
		pushup(i);
}
int main()
{
	char op[10];
	int a,b;
	while(~scanf("%d%d",&n,&m))
	{
		build();
		while(m--)
		{
			scanf("%s%d%d",op,&a,&b);
			if(op[0]=='Q')
				printf("%d\n",query(a,b));
			else
				update(a,b);
		}
	}
	return 0;
}
 ��������������������������������
��Ȩ����������ΪCSDN������RTFIL����ԭ�����£���ѭCC 4.0 by-sa��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/qq_43516113/article/details/89080732
