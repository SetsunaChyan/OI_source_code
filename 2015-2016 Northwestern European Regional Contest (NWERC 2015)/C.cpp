#include<bits/stdc++.h>
using namespace std;

#define db int
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
    void read(){scanf("%d%d",&x,&y);}
    void write(){printf("(%d,%d)\n",x,y);}
    db abs(){return sqrt(abs2());}
    db abs2(){return x*x+y*y;}
    P rot90(){return P(-y,x);}
    P unit(){return *this/abs();}
    int quad() const {return sign(y)==1||(sign(y)==0&&sign(x)>=0);}
    db dot(P p){return x*p.x+y*p.y;}
    db det(P p){return x*p.y-y*p.x;}
};

//For segment
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

bool intersect(db l1,db r1,db l2,db r2)
{
    if(l1>r1) swap(l1,r1);if(l2>r2) swap(l2,r2);
    return !(cmp(r1,l2)==-1||cmp(r2,l1)==-1);
}

bool isSS(P p1,P p2,P q1,P q2)
{
    return intersect(p1.x,p2.x,q1.x,q2.x)&&intersect(p1.y,p2.y,q1.y,q2.y)&&
    crossOp(p1,p2,q1)*crossOp(p1,p2,q2)<=0&&crossOp(q1,q2,p1)*crossOp(q1,q2,p2)<=0;
}

int vis[1005],n,m,flag=1;
P well[1005];
vector<int> e[1005];
struct pipe
{
	P st,ed;
}pp[1005];

void dfs(int now)
{
    for(auto to:e[now])
    {
        if(vis[to])
        {
            if(vis[to]==vis[now]) flag=0;
            continue;
        }
        vis[to]=-vis[now];
        dfs(to);
    }
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) well[i].read();
	for(int i=1,num;i<=m;i++)
	{
		scanf("%d",&num);
		pp[i].ed.read();
		pp[i].st=well[num];
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			if(pp[i].st==pp[j].st) continue;
			if(isSS(pp[i].st,pp[i].ed,pp[j].st,pp[j].ed))
                e[i].push_back(j),e[j].push_back(i);
		}
	for(int i=1;i<=m;i++)
        if(!vis[i]) vis[i]=1,dfs(i);
	if(flag) printf("possible"); else printf("impossible");
    return 0;
}

/*
3 3
0 0
0 2
2 0
1 2 3
2 2 2
3 0 3

2 3
0 0
0 10
1 5 15
1 2 15
2 10 10
*/
