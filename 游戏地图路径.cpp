// https://www.nowcoder.com/questionTerminal/a4b7f297ad0e46a0a1fbac4d2da83a63

#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, INF = 0x3f3f3f3f;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int n, sx, sy, tx, ty;
char g[N][N];
int dist[N][N];

int main() {
    cin >> n >> sy >> sx >> ty >> tx;
    for(int i = 0; i < n; i ++) cin >> g[i];

    queue<PII> que;
    que.push({sx, sy});

    memset(dist, 0x3f, sizeof dist);
    dist[sx][sy] = 0;

    while(que.size()) {
        auto tt = que.front(); que.pop();
        for(int i = 0; i < 4; i ++) {
            int a = tt.x + dx[i], b = tt.y + dy[i];
            if(a >= 0 && a < n && b >= 0 && b < n && g[a][b] != '#' && g[a][b] != '@') {
                if(dist[a][b] > dist[tt.x][tt.y] + 1) {
                    que.push({a, b});
                    dist[a][b] = dist[tt.x][tt.y] + 1;
                }
            }
        }
    }

    if(dist[tx][ty] == INF) puts("-1");
    else cout << dist[tx][ty] << "\n";

    return 0;
}