#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int l,n,a=0,b=0;
pair<int,int> pp[105];

int main()
{
    char opt[101];
    scanf("%s%d",opt,&n);
    l=strlen(opt);
    pp[0]=make_pair(0,0);
    for(int i=0;i<l;i++)
    {
        if(opt[i]=='L')
            a-=1;
        else if(opt[i]=='R')
            a+=1;
        else if(opt[i]=='U')
            b+=1;
        else
            b-=1;
        pp[i+1]=make_pair(a,b);
    }
    while(n--)
    {
        int x,y,flag=0;
        scanf("%d%d",&x,&y);
        for(int i=0;i<=l;i++)
        {
            if(a==0&&b==0)
            {
                if(pp[i].first==x&&pp[i].second==y)
                    flag=1;
            }
            else if(a)
            {
                if((pp[i].first-x)%a==0)
                {
                    int k=(x-pp[i].first)/a;
                    if(k>=0&&y==pp[i].second+b*k) flag=1;
                }
            }
            else if(b)
            {
                if((pp[i].second-y)%b==0)
                {
                    int k=(y-pp[i].second)/b;
                    if(k>=0&&x==pp[i].first+a*k) flag=1;
                }
            }
            if(flag) break;
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}