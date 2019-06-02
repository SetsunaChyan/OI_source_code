#include <bits/stdc++.h>
using namespace std;

int n,vis[5005],last,flg,sz,ans[4];

int main()
{
	//freopen("1.out","w",stdout); 
    int _;
    scanf("%d",&_);
    while(_--)
    {
    	scanf("%d",&n);
        last=n,flg=0,sz=0;
        memset(vis,0,sizeof(vis));
        while(last>3)
        {
            for(int i=0,j=0;i<n;i++)
            {
                if(!vis[i]) j++; else continue;
                if(j%2==0) vis[i]=1,last--;
                /*if(last<=3)
                {
                    flg=1;
                    break;
                }*/
            }
            if(last<=3) break;
            for(int i=0,j=0;i<n;i++)
            {
                if(!vis[i]) j++; else continue;
                if(j%3==0) vis[i]=1,last--;
                //if(last<=3) break;
            }
        }
        for(int i=0;i<n;i++)
            if(!vis[i]) ans[sz++]=i+1;
        for(int i=0;i<sz-1;i++)
        	printf("%d ",ans[i]);
        printf("%d\n",ans[sz-1]);
    }
    return 0;
}
