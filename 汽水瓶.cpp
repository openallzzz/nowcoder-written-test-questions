#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;

void solve() {
    int res = 0, cnt = n;
    while(cnt >= 3) {
        int t = cnt / 3;
        res += t;
        cnt = t + cnt % 3;
    }
    if(cnt == 2) res ++ ;

    cout << res << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    while(cin >> n, n) {
        solve();
    }

    return 0;
}