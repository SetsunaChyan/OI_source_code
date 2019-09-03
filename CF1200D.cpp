#include <bits/stdc++.h>
using namespace std;

const int MN = 2e3 + 5;

int n,k;
char ch[MN][MN];
int d[MN][MN],s[MN][MN],rs[MN],cs[MN],rk[MN][MN],ck[MN][MN],newr[MN][MN],newc[MN][MN],QAQ[MN][MN],QAQ2[MN][MN],ans;
int exnext[100],ex[100];

void get_exnext(string s)
{
    int n=s.size(),p=1,j,i;
    exnext[0]=n;
    for(i=0;i<n-1&&s[i]==s[i+1];i++);
    exnext[1]=i;
    for(i=2;i<n;i++)
        if(exnext[i-p]+i<p+exnext[p])
            exnext[i]=exnext[i-p];
        else
        {
            j=exnext[p]+p-i;
            if(j<0) j=0;
            while(i+j<n&&s[j]==s[i+j]) j++;
            exnext[i]=j;
            p=i;
        }
}

void exkmp(string s1,string s2)
{
    int l1=s1.size(),l2=s2.size(),p=0,i,j;
    get_exnext(s2);
    for(i=0;i<l1&&i<l2&&s1[i]==s2[i];i++);
    ex[0]=i;
    for(int i=1;i<l1;i++)
    {
        if(exnext[i-p]+i<p+ex[p])
            ex[i]=exnext[i-p];
        else
        {
            j=ex[p]+p-i;
            if(j<0) j=0;
            while(i+j<l1&&s1[i+j]==s2[j]) j++;
            ex[i]=j;
            p=i;
        }
    }
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%s",ch[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
        {
			d[i][j]=ch[i][j]=='B';
			rs[i]+=d[i][j];
			cs[j]+=d[i][j];
			s[i][j]=d[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
	for(int i=1;i<=n;++i)
		for(int j=k;j<=n;++j)
        {
			rk[i][j]=s[i][j]-s[i][j-k]-s[i-1][j]+s[i-1][j-k];
			newr[i][j]=(rs[i]&&rs[i]==rk[i][j]);
        }
	for(int i=k;i<=n;++i)
		for(int j=1;j<=n;++j)
        {
			ck[i][j]=s[i][j]-s[i-k][j]-s[i][j-1]+s[i-k][j-1];
			newc[i][j]=(cs[j]&&cs[j]==ck[i][j]);
        }
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
        {
			QAQ[i][j]=QAQ[i-1][j]+newr[i][j];
			if(i>k) QAQ[i][j]-=newr[i-k][j];
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
        {
			QAQ2[i][j]=QAQ2[i][j-1]+newc[i][j];
			if(j>k) QAQ2[i][j]-=newc[i][j-k];
		}
	for(int i=k;i<=n;++i)
		for(int j=k;j<=n;++j)
			ans=max(ans,QAQ[i][j]+QAQ2[i][j]);
	for(int t=1;t<=n;++t)
	{
		ans+=rs[t]==0;
		ans+=cs[t]==0;
	}
	printf("%d",ans);
	return 0;
}
