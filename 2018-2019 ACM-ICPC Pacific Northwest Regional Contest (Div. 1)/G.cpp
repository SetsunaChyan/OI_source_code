#include <bits/stdc++.h>
#define x1 x11
#define x2 x22
#define y1 y11
#define y2 y22
using namespace std;
int x,y,x1,y1,x2,y2;
double dist(int x1,int y1,int x2,int y2) {
    return sqrt((double)(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
void print(double p) {
    printf("%.3f\n",p);
}
int main()
{
    scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
    if (x>=x2&&y>=y2) {
            print(dist(x,y,x2,y2));
            return 0;
    }
    if (x<=x1&&y>=y2) {
            print(dist(x,y,x1,y2));
            return 0;
    }
    if (x<=x1&&y<=y1) {
            print(dist(x,y,x1,y1));
            return 0;
    }
    if (x>=x2&&y<=y1) {
            print(dist(x,y,x2,y1));
            return 0;
    }
    if (x>=x2) {
            print(x-x2);
            return 0;
    }
    if (x<=x1) {
            print(x1-x);
            return 0;
    }
    if (y<=y1) {
            print(y1-y);
            return 0;
    }
    if (y>=y2) {
            print(y-y2);
            return 0;
    }
    return 0;
}
