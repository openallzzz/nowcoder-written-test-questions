#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n;
int p[N];

void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> p[i];

    sort(p, p + n);
    for(int i = 0; i < n; i ++) {
        int j = i;
        while(j < n && p[j] == p[i]) j ++ ;
        cout << p[i] << "\n";
        i = j - 1;
    }

}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    solve();
    return 0;
}