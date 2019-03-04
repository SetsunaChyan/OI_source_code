#include <cstdio>
#include <algorithm>
#include <cmath>

struct bignum
{
    int num[100000],len;
}ans,max,temp;

struct node
{
    int a,b;
}g,s[1000];

bool cmp(node a,node b)
{
    return a.a*a.b<b.a*b.b;
}

void print(bignum &a)
{
    for(int i=a.len-1;i>=0;i--)
        printf("%d",a.num[i]);
    if(a.len==0) printf("0");
    printf("\n");
}

void multiply(bignum &a,int b)
{
    int jw=0,k=log10(b)+1;
    a.len+=k;
    for(int i=0;i<a.len;i++)
    {
        a.num[i]*=b;
        a.num[i]+=jw;
        jw=a.num[i]/10;
        a.num[i]%=10;
    }
    while(a.num[a.len-1]==0&&a.len>0) a.len--;
}

bignum div(bignum a,int b)
{
    bignum c;
    int q=0,l=log10(b)+1;
    c.len=a.len-l+1;
    if(c.len<1) c.len=1;
    for(int i=a.len-l+1,p=1;i<a.len;p*=10,i++)
    {
        q+=p*a.num[i];
    }
    for(int i=a.len-l;i>=0;i--)
    {
        q*=10;
        q+=a.num[i];
        c.num[i]=q/b;
        q%=b;
    }
    while(c.num[c.len-1]==0&&c.len>0) c.len--;
    return c;
}

bool compare(const bignum &a,const bignum &b)
{
    if(a.len>b.len) return true;
    if(a.len<b.len) return false;
    for(int i=a.len-1;i>=0;i--)
    {
        if(a.num[i]>b.num[i]) return true;
        if(a.num[i]<b.num[i]) return false;
    }
    return false;
}

int main()
{
    //freopen("P1080in.txt","r",stdin);
    int n,p=0;
    ans.len=0;
    ans.num[0]=0;
    scanf("%d",&n);
    scanf("%d%d",&g.a,&g.b);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&s[i].a,&s[i].b);
    }
    std::sort(s,s+n,cmp);
    while(g.a)
    {
        ans.num[p]=g.a%10;
        g.a/=10;
        ans.len++;
        p++;
    }
    max=ans;
    for(int i=0;i<n-1;i++)
    {
        temp=div(ans,s[i].b);
        if(compare(temp,max)) max=temp;
        multiply(ans,s[i].a);
    }
    temp=div(ans,s[n-1].b);
    if(compare(temp,max)) max=temp;
    print(max);
    return 0;
}
