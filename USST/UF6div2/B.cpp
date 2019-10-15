#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
char s[1000];
int l;
ll xa,xb,ax,bx,ab,ba,xx,aa,bb;

void solve(int l,int r,ll &xa,ll &xb,ll &ax,ll &bx,ll &ab,ll &ba,ll &xx,ll &aa,ll &bb)
{
    xa=xb=ax=bx=1;
    ab=ba=xx=aa=bb=0;
    if(l==r-1) return;
    int now=l,stk=0,flag=0;
    ll nxa,nxb,nax,nbx,nab,nba,nxx,naa,nbb;
    nxa,nxb,nax,nbx=1,nab=nba=nxx=naa=nbb=0;
    while(now<=r)
    {
        for(int i=l;i<=r;i++)
        {
            if(s[i]=='(') stk++;
            else stk--;
            if(stk==0&&i==r&&now==l)
            {
                ll txa,txb,tax,tbx,tab,tba,txx,taa,tbb;
                solve(l+1,r-1,txa,txb,tax,tbx,tab,tba,txx,taa,tbb);
                xa=txb+tax+tbx+tab+txb+txx,xa%=mod;
                xb=txa+tax+tbx+tba+txa+txx,xb%=mod;
                ax=tbx+txa+txb+tba+tbx+txx,ax%=mod;
                bx=tax+txa+txb+tab+tax+txx,bx%=mod;
                ab=txx+txa+tbx+tba,ab%=mod;
                ba=txx+txb+tax+tab,ba%=mod;
                aa=tbb+txx,aa%=mod;
                bb=taa+txx,bb%=mod;
                return;
            }
            if(stk==0)
            {
                if(flag==0)
                {
                    solve(now,i,xa,xb,ax,bx,ab,ba,xx,aa,bb);
                    now=i+1;
                    flag++;
                    break;
                }
                ll txa,txb,tax,tbx,tab,tba,txx,taa,tbb;
                solve(now,i,txa,txb,tax,tbx,tab,tba,txx,taa,tbb);
                nxa=xa,nxb=xb,nax=ax,nbx=bx,nab=ab,nba=ba,nxx=xx,naa=aa,nbb=bb;
                nxa=(txb+tax+tbx+tab+txb+txx)%mod*,xa%=mod;
                nxb*=(txa+tax+tbx+tba+txa+txx),xb%=mod;
                nax*=tbx+txa+txb+tba+tbx+txx,ax%=mod;
                nbx*=tax+txa+txb+tab+tax+txx,bx%=mod;
                nab*=txx+txa+tbx+tba,ab%=mod;
                nba*=txx+txb+tax+tab,ba%=mod;
                naa*=tbb+txx,aa%=mod;
                nbb*=taa+txx,bb%=mod;
                xa=nxa,xb=nxb,ax=nax,bx=nbx,ab=nab,ba=nba,xx=nxx,aa=naa,bb=nbb;
                now=i+1;
                break;
            }
        }
    }
}

int main()
{
    scanf("%s",s);
    l=strlen(s);
    solve(1,l,xa,xb,ax,bx,ab,ba,xx,aa,bb);
    printf("%lld",(xa+xb+ax+bx+ab+ba+xx+aa+bb)%mod);
    return 0;
}
