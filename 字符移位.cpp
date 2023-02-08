#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e5 + 10;

string s;

void solve() {
    int l = -1, r = -1, k = N; // k = 0
    for(int i = s.size() - 1; i >= 0; i --) {
        if(s[i] <= 'Z' && s[i] >= 'A') k = i;
        else {
            int j = i;
            while(j >= 0 && s[j] <= 'z' && s[j] >= 'a') j -- ;

            l = j + 1, r = i;
            i = j + 1;
        }

        cout << k << " " << l << " " << r << endl;

        if(k < l) {
            char bak = s[k];
            for(int j = k; j < r; j ++) {
                s[j] = s[j + 1];
            }
            s[r] = bak;

            l --, r --, k = N;
            while(l >= 0 && s[l] >= 'a' && s[l] <= 'z') l -- ;
            l ++ ;
            i = l;
        }

        // cout << s << endl;
    }

    cout << s << "\n";
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