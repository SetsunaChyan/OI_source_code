#include<bits/stdc++.h>
using namespace std;
//#define ll long long
#define LL long long
#define ull unsigned long long
#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%lld",&a)
#define pr(a) printf("%d",a)
#define per(a,b,c) for(int a=b;a<c;++a)
#define perr(a,b,c) for(int a=b;a<=c;++a)
const int inf=0x3f3f3f3f;
const int mod=2;

int _;

LL ex_gcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    LL r=ex_gcd(b,a%b,x,y);
    LL t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

///n个mi不互质
const LL maxn = 1000;
LL a[maxn], m[maxn], n;
LL CRT(LL a[], LL m[], LL n) {
    if (n == 1) {
        if (m[0] > a[0]) return a[0];
        else return -1;
    }
    LL x, y, d;
    for (int i = 1; i < n; i++) {
        if (m[i] <= a[i]) return -1;
        d = ex_gcd(m[0], m[i], x, y);
        if ((a[i] - a[0]) % d != 0) return -1;  //不能整除
        LL t = m[i] / d;
        x = ((a[i] - a[0]) / d * x % t + t) % t;
        a[0] = x * m[0] + a[0];
        m[0] = m[0] * m[i] / d;
        a[0] = (a[0] % m[0] + m[0]) % m[0];
    }
    return a[0];
}
set<LL>s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    LL f,f1=1,f2=1;

    per(i,1,90){
        f=f1+f2;
        f1=f2;
        f2=f;
        s.insert(f);
    }

    cin>>n;
    per(i,0,n){
        cin>>m[i]>>a[i];
    }
    LL N=CRT(a,m,n);
    if(N<=-1||N>1LL*1e15)
        cout<<"Tankernb!"<<endl;
    else if(!s.count(N)){
        cout<<"Zgxnb!"<<endl;
    }
    else cout<<"Lbnb!"<<endl;
    return 0;
}
