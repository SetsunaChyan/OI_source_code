#include<bits/stdc++.h>
using namespace std;
#define per(i,a,n) for(int i=a;i<=n;++i)
#define rep(i,a,n) for(int i=a;i>=n;--i)
#define ll long long
#define mem(a) memset(a,0,sizeof(a))
int a[10006];
int b[10006];
int main()
{
    int t;
    cin>>t;
    int n;
    int pp;
    while(t--)
    {
    	mem(a);
    	mem(b);
    	scanf("%d",&n);int k=-1;
    	per(i,1,n)
    	 {
    	 	scanf("%d",&pp);
    	    ++a[pp];
    	    if(a[pp]==2)b[++k]=pp;
    	    if(a[pp]==4)b[++k]=pp;
    	 }
    	sort(b,b+k+1);
    	int mincha=10001;
    	int mini=0;
    	per(i,0,k-1)
    	 if(b[i+1]-b[i]<mincha)
    	 {
    	 	mincha=b[i+1]-b[i];
    	 	mini=i;
    	 	if(mincha==0)break;
    	 }
    	printf("%d %d %d %d\n",b[mini],b[mini],b[mini+1],b[mini+1] );
    }
    return 0;
}