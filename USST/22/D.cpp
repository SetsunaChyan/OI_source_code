#include <cstdio>

char s[200005];
int n,b,a,ans;

inline int min(int a,int b){return a<b?a:b;}

int main()
{
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",s);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='.')
        {
            int j,t;
            for(j=i+1;j<n;j++)
                if(s[j]!='.') break;
            int k=j-i;
            i=j-1;
            if(a>b)
            {
                t=min((k+1)/2,a);
                ans+=t;
                a-=t;
                t=min(k/2,b);
                ans+=t;
                b-=t;
            }
            else
            {
                t=min((k+1)/2,b);
                ans+=t;
                b-=t;
                t=min(k/2,a);
                ans+=t;
                a-=t;
            }
            if(a<=0&&b<=0) 
                break;
        }
    }
    printf("%d",ans);
    return 0;
}