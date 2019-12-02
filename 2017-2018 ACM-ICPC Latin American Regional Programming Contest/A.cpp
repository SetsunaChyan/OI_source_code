#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define db double
const db EPS=1e-9;
inline int sign(db a){return a<-EPS?-1:a>EPS;}
inline int cmp(db a,db b){return sign(a-b);}
struct P
{
    db x,y;
    P(){}
    P(db x,db y):x(x),y(y){}
    P operator+(P p){return {x+p.x,y+p.y};}
    P operator-(P p){return {x-p.x,y-p.y};}
    P operator*(db d){return {x*d,y*d};}
    P operator/(db d){return {x/d,y/d};}
    bool operator<(P p) const
    {
        int c=cmp(x,p.x);
        if(c) return c==-1;
        return cmp(y,p.y)==-1;
    }
    bool operator==(P o) const
    {
        return cmp(x,o.x)==0&&cmp(y,o.y)==0;
    }
    db distTo(P p){return (*this-p).abs();}
    db alpha(){return atan2(y,x);}
    void read(){scanf("%lf%lf",&x,&y);}
    void write(){printf("(%.10f,%.10f)\n",x,y);}
    db abs(){return sqrt(abs2());}
    db abs2(){return x*x+y*y;}
    P rot90(){return P(-y,x);}
    P unit(){return *this/abs();}
    int quad() const {return sign(y)==1||(sign(y)==0&&sign(x)>=0);}
    db dot(P p){return x*p.x+y*p.y;}
    db det(P p){return x*p.y-y*p.x;}
    P rot(db an){return {x*cos(an)-y*sin(an),x*sin(an)+y*cos(an)};}
};

//For segment
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

bool chkLL(P p1,P p2,P q1,P q2) //0:parallel
{
    db a1=cross(q1,q2,p1),a2=-cross(q1,q2,p2);
    return sign(a1+a2)!=0;
}

inline P isLL(P &p1,P &p2,P &q1,P &q2) //crossover point if chkLL()
{
    db a1=cross(q1,q2,p1),a2=-cross(q1,q2,p2);
    return (p1*a2+p2*a1)/(a1+a2);
}

inline bool intersect(db l1,db r1,db l2,db r2)
{
    if(l1>r1) swap(l1,r1);if(l2>r2) swap(l2,r2);
    return !(cmp(r1,l2)==-1||cmp(r2,l1)==-1);
}

inline bool isSS(P &p1,P &p2,P &q1,P &q2)
{
    return intersect(p1.x,p2.x,q1.x,q2.x)&&intersect(p1.y,p2.y,q1.y,q2.y)&&
    crossOp(p1,p2,q1)*crossOp(p1,p2,q2)<=0&&crossOp(q1,q2,p1)*crossOp(q1,q2,p2)<=0;
}

bool isSS_strict(P p1,P p2,P q1,P q2)
{
    return crossOp(p1,p2,q1)*crossOp(p1,p2,q2)<0
    &&crossOp(q1,q2,p1)*crossOp(q1,q2,p2)<0;
}

bool isMiddle(db a,db m,db b)
{
    return sign(a-m)==0||sign(b-m)==0||(a<m!=b<m);
}

bool isMiddle(P a,P m,P b)
{
    return isMiddle(a.x,m.x,b.x)&&isMiddle(a.y,m.y,b.y);
}

bool onSeg(P p1,P p2,P q)
{
    return crossOp(p1,p2,q)==0&&isMiddle(p1,q,p2);
}

bool onSeg_strict(P p1,P p2,P q)
{
    return crossOp(p1,p2,q)==0&&sign((q-p1).dot(p1-p2))*sign((q-p2).dot(p1-p2))<0;
}

P proj(P p1,P p2,P q)
{
    P dir=p2-p1;
    return p1+dir*(dir.dot(q-p1)/dir.abs2());
}

P reflect(P p1,P p2,P q)
{
    return proj(p1,p2,q)*2-q;
}

db nearest(P p1,P p2,P q)
{
    P h=proj(p1,p2,q);
    if(isMiddle(p1,h,p2))
        return q.distTo(h);
    return min(p1.distTo(q),p2.distTo(q));
}

db disSS(P p1,P p2,P q1,P q2) //dist of 2 segments
{
    if(isSS(p1,p2,q1,q2)) return 0;
    return min(min(nearest(p1,p2,q1),nearest(p1,p2,q2)),min(nearest(q1,q2,p1),nearest(q1,q2,p2)));
}

db rad(P p1,P p2)
{
    return atan2l(p1.det(p2),p1.dot(p2));
}

db area(vector<P> ps)
{
    db ret=0;
    for(int i=0;i<ps.size();i++)
        ret+=ps[i].det(ps[(i+1)%ps.size()]);
    return ret/2;
}

int contain(vector<P> ps,P p) //2:inside,1:on_seg,0:outside
{
    int n=ps.size(),ret=0;
    for(int i=0;i<n;i++)
    {
        P u=ps[i],v=ps[(i+1)%n];
        if(onSeg(u,v,p)) return 1;
        if(cmp(u.y,v.y)<=0) swap(u,v);
        if(cmp(p.y,u.y)>0||cmp(p.y,v.y)<=0) continue;
        ret^=crossOp(p,u,v)>0;
    }
    return ret*2;
}

vector<P> convexHull(vector<P> ps)
{
    int n=ps.size();if(n<=1) return ps;
    sort(ps.begin(),ps.end());
    vector<P> qs(n*2);int k=0;
    for(int i=0;i<n;qs[k++]=ps[i++])
        while(k>1&&crossOp(qs[k-2],qs[k-1],ps[i])<=0) --k;
    for(int i=n-2,t=k;i>=0;qs[k++]=ps[i--])
        while(k>t&&crossOp(qs[k-2],qs[k-1],ps[i])<=0) --k;
    qs.resize(k-1);
    return qs;
}

db convexDiameter(vector<P> ps)
{
    int n=ps.size();if(n<=1) return 0;
    int is=0,js=0;
    for(int k=1;k<n;k++) is=ps[k]<ps[is]?k:is,js=ps[js]<ps[k]?js:k;
    int i=is,j=js;
    db ret=ps[i].distTo(ps[j]);
    do{
        if((ps[(i+1)%n]-ps[i]).det(ps[(j+1)%n]-ps[j])>=0) (++j)%=n;
        else (++i)%=n;
        ret=max(ret,ps[i].distTo(ps[j]));
    }while(i!=is||j!=js);
    return ret;
}

int n,UP=55;
double dis[16][16],H,dp[1<<16][16],X[16];
vector<P> con[16];

double cal(double h,vector<P> &a,vector<P> &b)
{
	vector<double> v1,v2;
	P q1=P(-1e10,h),q2=P(1e10,h);
	for(register int i=0;i<a.size();i++)
	{
		if(isSS(a[i],a[(i+1)%a.size()],q1,q2))
			v1.push_back(isLL(a[i],a[(i+1)%a.size()],q1,q2).x);
		if(v1.size()==2) break;
	}
	for(register int i=b.size()-1;i>=0;i--)
	{
		if(isSS(b[i],b[(i+1)%b.size()],q1,q2))
			v2.push_back(isLL(b[i],b[(i+1)%b.size()],q1,q2).x);
		if(v2.size()==2) break;
	}
	return min(v2[0],v2[1])-max(v1[1],v1[0]);
}

inline double gao(vector<P> &a,vector<P> &b,double &X,double &Y)
{
	double l=1e-6,r=H-1e-6,lm,rm;
	for(auto p:a) X=max(p.x,X);
	for(auto p:b) Y=max(p.x,Y);
	for(register int i=0;i<UP;i++)
	{
	    double lm=(l+r)/2,rm=(lm+r)/2;
	    if(cal(lm,a,b)>cal(rm,a,b)) l=lm;
	    else r=rm;
	}
	return Y-cal((l+r)/2,a,b)-X;
}

inline double gao2(int x)
{
	double X=-1e18,Y=1e18;
	for(auto p:con[x]) X=max(p.x,X),Y=min(p.x,Y);
	::X[x]=X;
	return X-Y;
}

int main()
{
	int sum=0;
	scanf("%d",&n);
	for(register int i=0,x;i<n;i++)
	{
		scanf("%d",&x);sum+=x;
		for(register int j=0;j<x;j++)
		{
			double x,y;
			scanf("%lf%lf",&x,&y);
			H=max(H,y);
			con[i].emplace_back(x,y);
		}
	}
	if(sum<2e4) UP=100;
	for(register int i=0;i<(1<<(n+1));i++)
		for(register int j=0;j<=n;j++)
			dp[i][j]=1e18;
	for(register int i=0;i<n;i++) dis[0][i+1]=gao2(i);
	for(register int i=0;i<n;i++)
		for(register int j=0;j<n;j++)
			if(i!=j) dis[i+1][j+1]=gao(con[i],con[j],X[i],X[j]);
	n++;
	for(register int i=1;i<n;i++) dis[0][i]=gao2(i-1);
	dp[1][0]=0;
	for(register int i=1;i<(1<<n);i++)
		for(register int j=0;j<n;j++)
			if((i>>j)&1)
				for(register int k=0;k<n;k++)
					if((i>>k)&1)
						dp[i][j]=min(dp[i][j],dp[i^(1<<j)][k]+dis[k][j]);
	double ans=1e18;
	for(register int i=1;i<n;i++) ans=min(ans,dp[(1<<n)-1][i]);
	printf("%.3f",ans);
	return 0;
}
