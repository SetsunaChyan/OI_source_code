#include <cstdio>

typedef long long ll;
int flag=0,n,a[200005],m=0;

inline int max(int a,int b){return a>b?a:b;}

bool test(int m)
{
    int black=0,white=0;
    for(int i=0;i<n;i++)
    {
        int k=(m-a[i])/2;
        if(i&1)
        {
            white+=k;
            black+=(m-a[i])-k;
        }
        else
        {
            white+=(m-a[i])-k;
            black+=k;
        }
    }
    if(black==white) return true;
    return false;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        m=max(m,a[i]);
    }
    if(test(m)||test(m+1))
        printf("YES");
    else
        printf("NO");
    return 0;
}