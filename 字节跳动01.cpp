#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e5 + 10;

int n, m, ans;
vector<int> nums;
string s;

void dfs(int u, int p, bool eq) {
    if(u == s.size()) {
        if(p < n) ans = max(ans, p);
        return ;
    }

    for(int i = 0; i < m; i ++) {
        if(eq && nums[i] > s[u] - '0') continue;
        if(eq && nums[i] == s[u] - '0' && u == s.size() - 1) continue;

        dfs(u + 1, p * 10 + nums[i], eq && nums[i] == s[u] - '0');
    }
}

void solve() {
    cin >> n; // 给定的数字n
    cin >> m; // 给定数字集大小

    for(int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    s = to_string(n);

    // 答案的位数比 n 小一位
    int mxV = 0;
    for(int i = 0; i < m; i ++) mxV = max(mxV, nums[i]);
    ans = stoi(string(m - 1, '0' + mxV));

    // 爆搜的结果的位数固定为 n 的位数
    dfs(0, 0, true);

    cout << ans << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    int T = 1;
    if(cinT) cin >> T;
    while(T --) {
        solve();
    }

    return 0;
}