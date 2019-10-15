#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int p1=998244353,p2=19260817;
//set<pii> s;
set<int> s;
char a[4005],b[4005];
int n1,n2,ans,cnt[26],qp[30][2];

int main()
{
    scanf("%s%s",a,b);
    /*srand(time(0));
    for(int i=0;i<4000;i++)
        a[i]=b[i]='a'+rand()%26;
    a[4000]=b[4000]=0;*/
    n1=strlen(a),n2=strlen(b);
    qp[0][0]=qp[0][1]=1;
    for(int i=1;i<30;i++)
   		qp[i][0]=ll(qp[i-1][0])*4001%p1,qp[i][1]=ll(qp[i-1][1])*4001%p2;
	for(int i=0;i<n1;i++)
    {
        ll now=0,now2=0;
        int t;
        for(int j=i;j<n1;j++)
        {
        	t=a[j]-'a'+1;
        	now+=ll(t)*qp[t][0]+1,now%=p1;
        	//now2+=ll(t)*qp[t][1]+1,now2%=p2;
			//s.insert({now,now2});
			s.insert(now);
		}
    }
    for(int i=0;i<n2;i++)
    {
        ll now=0,now2=0;
        int t;
        for(int j=i;j<n2;j++)
        {
            t=b[j]-'a'+1;
        	now+=ll(t)*qp[t][0]+1,now%=p1;
        	//now2+=ll(t)*qp[t][1]+1,now2%=p2;
			//if(s.find({now,now2})!=s.end()) ans=max(ans,j-i+1);
			if(s.find(now)!=s.end()) ans=max(ans,j-i+1);
		}
    }
    printf("%d",ans);
    return 0;
}
