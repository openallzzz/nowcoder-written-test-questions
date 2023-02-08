#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e3 + 10;

string s, t;
int f[N][N];

void solve() {
    t = "";
    for(int i = s.size() - 1; i >= 0; i --) t += s[i];

    memset(f, 0, sizeof f);

    int n = s.size(), m = n;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++) {
            if(s[i - 1] == t[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }

    cout << n - f[n][n] << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    // int T = 1;
    // if(cinT) cin >> T;
    while(cin >> s) {
        solve();
    }

    return 0;
}