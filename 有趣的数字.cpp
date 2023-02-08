#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e6 + 10;

int n;
int a[N];

void solve() {
    for(int i = 0; i < n; i ++) cin >> a[i];

    unordered_map<int, int> c1, c2;

    sort(a, a + n);

    int x = 0, y = 0;
    int minV = INT_MAX, maxV = a[n - 1] - a[0];
    for(int i = 0; i + 1 < n; i ++) minV = min(minV, a[i + 1] - a[i]);

    for(int i = 0, j = n - 1; i < n && j >= 0; i ++, j --) {
        x += c1[a[i] - minV];
        y += c2[a[j] + maxV];
        c1[a[i]] ++ , c2[a[j]] ++ ;
    }

    cout << x << ' ' << y << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    // int T = 1;
    // if(cinT) cin >> T;
    while(cin >> n) {
        solve();
    }

    return 0;
}