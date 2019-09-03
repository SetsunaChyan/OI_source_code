#include <bits/stdc++.h>
using namespace std;

int n,m,k,a[100],tmp[100],ans=0,p[100];

bool dfs(int now,int sum,int qaq)
{
    bool ret=true;
    if(now==n)
    {
        /*for(int i=0;i<n;i++) p[i]=i+1;
        int fflag=1;
        do
        {
            int flag=1,solved=0;
            for(int i=0;i<n;i++)
                if(a[p[i]-1]<qaq) solved++;
            if(solved<k)
            {
                fflag=0;
                break;
            }
        }while(next_permutation(p,p+n));
        if(fflag) return true;
        return false;*/
        int flag=1,solved=0;
        for(int i=0;i<n;i++)
            if(a[i]<qaq) solved++;
        if(solved<k)
        {
            flag=0;

        }
        return flag;
    }
    for(int i=0;i<=sum;i++)
    {
        a[now]=i;
        ret=ret&&dfs(now+1,sum-i,qaq);
        if(!ret) return ret;
    }
    return ret;
}

int main()
{
   // scanf("%*d");
    scanf("%d%d%d",&n,&m,&k);
    for(int qaq=0;qaq<=(m+1)*n;qaq++)
    {
        if(dfs(0,0,qaq))
        {
            printf("%d\n",qaq);
            //break;
        }
    }
    //printf("%d",ans);
    return 0;
}
