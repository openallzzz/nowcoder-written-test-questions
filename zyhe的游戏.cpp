#include <bits/stdc++.h>

#define x first
#define y second

// @author: openallzzz
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;

const int N = 1e2 + 10, INF = 0x3f3f3f3f;

LL n, sx, sy, tx, ty;
struct circle {
    LL x, y, r;
    // bool operator>(const circle& c) const {
    //     return r < c.r;
    // }
}cs[N];
bool st[N];
int dist[N];

LL get_dist_2(int x, int y, int i) {
    return (x - cs[i].x) * (x - cs[i].x) 
        + (y - cs[i].y) * (y - cs[i].y);
}

int main() {
    cin >> n >> sx >> sy >> tx >> ty;
    for(int i = 0; i < n; i ++) cin >> cs[i].x >> cs[i].y >> cs[i].r;

    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);

    queue<int> q;
    for(int i = 0; i < n; i ++) {
        if(get_dist_2(sx, sy, i) <= 1e6) {
            q.push(i);
            st[i] = true;
            dist[i] = 0;
        }
    }

    while(q.size()) {
        auto u = q.front(); q.pop();
        if(get_dist_2(tx, ty, u) <= cs[u].r * cs[u].r) {
            cout << dist[u] + 1 << "\n";
            return 0;
        }

        for(int i = 0; i < n; i ++) {
            if(!st[i] && get_dist_2(cs[u].x, cs[u].y, i) <= cs[u].r * cs[u].r) {
                st[i] = true;
                if(dist[i] > dist[u] + 1) {
                    q.push(i);
                    dist[i] = dist[u] + 1;
                }
            }
        }
    }

    cout << "-1" << "\n";
    return 0;
}