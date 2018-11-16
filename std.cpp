#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <iostream>
 
using namespace std;

const long long N = 10050;
const long long INF = 1e8;
 
struct line
{
    long long l, r;
    long long sum;
    long long add;
}tree[8*N];
 
struct node
{
    long long w, h;
    long long val;
    bool operator < (const struct node & tmp) const
    {
        if(w == tmp.w)
            return val < tmp.val;
        return w < tmp.w;
    }
}point[8*N];
 
long long y[N*8];
 
void build(long long i, long long l, long long r)
{
    tree[i].l = l;
    tree[i].r = r;
    tree[i].add = 0;
    tree[i].sum = 0;
    if(l == r)
    {
        return;
    }
    long long mid = (l+r) >> 1;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
}
 
long long binsearch(long long key, long long k)
{
    long long high = k;
    long long low = 1;
    while(high >= low)
    {
        long long mid = (high+low) >> 1;
        if(y[mid] == key)
        {
            return mid;
        }
        else if(y[mid] < key)
        {
            low = mid+1;
        }
        else high = mid-1;
    }
    return -1;
}
 
 
void update(long long i, long long l, long long r, long long val)
{
    if(tree[i].l == l && tree[i].r == r)
    {
        tree[i].add += val;
        tree[i].sum += val;
        return;
    }
    if(tree[i].add)
    {
        tree[i*2].add += tree[i].add;
        tree[i*2+1].add += tree[i].add;
        tree[i*2].sum += tree[i].add;
        tree[i*2+1].sum += tree[i].add;
        tree[i].add = 0;
    }
    long long mid = (tree[i].l+tree[i].r) >> 1;
    if(mid >= r)
        update(i*2, l, r, val);
    else if(mid < l)
        update(i*2+1, l, r, val);
    else
    {
        update(i*2, l, mid, val);
        update(i*2+1, mid+1, r, val);
    }
    tree[i].sum = max(tree[i*2].sum, tree[i*2+1].sum);
}
 
int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("data2.out","w",stdout);
    long long n, w, h;
    while(~scanf("%lld%lld%lld", &n, &w, &h))
    {
        for(long long i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld", &point[i].w, &point[i].h, &point[i].val);
            y[i] = point[i].h;
            y[i+n] = point[i].h+h;
            point[i+n].w = point[i].w+w;
            point[i+n].h = point[i].h;
            point[i+n].val = -point[i].val;
        }
        sort(point+1, point+1+n*2);
        sort(y+1, y+1+n*2);
        long long k = 1;
        for(long long i = 2; i <= n*2; i++)
        {
            if(y[i-1] != y[i])
            {
                y[++k] = y[i];
            }
        }
        build(1, 1, k);
        long long ans = 0;
        for(long long i = 1; i <= n*2; i++)
        {
            long long l = binsearch(point[i].h, k);
            long long r = binsearch(point[i].h+h, k)-1;
            if(l > r) swap(l, r);
          //  printf("%lld %lld\n", l, r);
            update(1, l, r, point[i].val);
            ans = max(ans, tree[1].sum);
        }
        printf("%lld\n", ans);
    }
    return 0;
}