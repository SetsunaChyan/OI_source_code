#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const double EPS=1e-3;
#define db ll
inline int sign(db a){return a<-EPS?-1:a>EPS;}
inline int cmp(db a,db b){return sign(a-b);}
inline double _abs(double x){return x<0?-x:x;}
struct P
{
    ll x,y;
    P(ll x=0,ll y=0):x(x),y(y){}
    P operator-(P p){return {x-p.x,y-p.y};}
    bool operator <(const P &b)
    {
        double d1=atan2(y,x),d2=atan2(b.y,b.x);
        if(_abs(d1-d2)>1e-3) return d1<d2;
        return det(b)>0;
    }
    bool operator==(P o)
    {
        return !((*this)<o)&&!(o<(*this));
    }
    db det(P p){return x*p.y-y*p.x;}
};

int n,cur;
ll c[1005];
P a[1005],v[1005*1005];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld%lld",&a[i].x,&a[i].y,c+i);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(c[i]<c[j]) v[cur++]=a[j]-a[i];
    sort(v,v+cur);
    cur=unique(v,v+cur)-v;
    if(cur==0) return printf("Y"),0;
    v[cur]=v[0];
    for(int i=0;i<cur;i++)
        if(v[i].det(v[i+1])<=0) return printf("Y"),0;
    printf("N");
    return 0;
}
