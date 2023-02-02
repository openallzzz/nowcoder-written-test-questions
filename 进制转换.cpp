#include <bits/stdc++.h>

using namespace std;

int get(char c) {
    if(c >= '0' && c <= '9') return c - '0';
    return 10 + c - 'A';
}

void solve() {
    string s;
    cin >> s;

    int res = 0;
    for(int i = 2; i < s.size(); i ++) res = res * 16 + get(s[i]);

    cout << res << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    solve();
    return 0;
}