#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010, M = 200010;

int n, m, p[N], a[N];
struct edge {
    int x, y;
    LL w;
    bool operator < (const edge &e) const {
        return w < e.w;
    }
}edges[M];

int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 0; i < m; i ++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        w -= a[x] + a[y]; // 一条边连接的话，端点的权值可以提供相应的费用
        edges[i] = {x, y, w};
    }

    sort(edges, edges + m);
    for(int i = 1; i <= n; i ++) p[i] = i;

    LL res = 0;
    for(int i = 0; i < m; i ++) {
        int x = edges[i].x, y = edges[i].y, w = edges[i].w;
        x = find(x), y = find(y);
        if(x != y) p[x] = y, res = res + 0ll + w;
    }

    printf("%lld\n", res);
    return 0;
}