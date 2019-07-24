#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

// edge
struct Edge{
    int from, to, f, w;
}E[1000005];
int Hed[100005], Nex[1000005], ct=1, Cur[100005];
void Add(int a, int b, int f, int w){  //�ӱ�
    E[++ct].from=a, E[ct].to=b, E[ct].f=f, E[ct].w=w, Nex[ct]=Hed[a], Hed[a]=ct;
    E[++ct].from=b, E[ct].to=a, E[ct].f=0, E[ct].w=-w, Nex[ct]=Hed[b], Hed[b]=ct;
}

// mincostmaxflow
int n, m, s, t, maxflow, mincost, Dis[100005], F[100005];
bool SPFA(){  //���·�ֲ㣬�ӻ����Դ��ֲ��ܱ�֤DFS�ߵ�һ�������·�������˷�ʱ���ߴ�·
    queue<int> Q; Q.push(s);
    memset(Dis, INF, sizeof Dis);
    Dis[s] = 0; int k;
    while(!Q.empty()){
        k = Q.front(); Q.pop();
        F[k] = 0;
        for(int i=Hed[k]; i; i=Nex[i]){
            if(E[i].f && Dis[k]+E[i].w<Dis[E[i].to]){
                Dis[E[i].to] = Dis[k]+E[i].w;
                if(!F[E[i].to])
                    Q.push(E[i].to), F[E[i].to] = 1;
            }
        }
    }
    return Dis[t] != INF;
}
int DFS(int k, int flow){
    if(k == t){maxflow += flow; return flow;}  //�ﵽ�����������
    int sum = 0; F[k] = 1;  //F[]��֤�˵����� 0 ���ñߵ�ʱ�򲻻����������֮�������ܵ����
    for(int i=Cur[k]; i; i=Nex[i]){
        if(!F[E[i].to] && E[i].f  && Dis[E[i].to]==Dis[k]+E[i].w){
        	Cur[k] = i;  //��ǰ���Ż�
            int p = DFS(E[i].to, min(flow-sum, E[i].f));
            sum += p, E[i].f -= p, E[i^1].f += p, mincost += p*E[i].w;  //���·���
            if(sum == flow) break;
        }
    }
    F[k] = 0;
    return sum;
}
void Dinic(){
    while(SPFA()){
    	memcpy(Cur, Hed, sizeof Hed);
    	DFS(s, INF);
	}
}

// main
int main(){

    freopen("testdata.in","r",stdin);
    int a, b, c, d;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i=1; i<=m; ++i){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        Add(a, b, c, d);
    }
    Dinic();
    printf("%d %d", maxflow, mincost);
    return 0;
}
