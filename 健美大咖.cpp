#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int n, m, a[N], b[N][N], number = N;
int record[N];
vector<int> res, path;
void dfs(int u, int cnt) {
    bool flag = false;
    for(int i = 1; i <= n; i ++) {
        if(a[i] > record[i]) break;
        else if(i == n && a[i] <= record[i]) flag = true;
    }
    
    if(flag) {
        if(cnt < number) {
            number = cnt;
            res = path;
        }
        return ;
    }
    
    if(u == m + 1) return ;

    // 选择第u个套餐
    path.push_back(u);
    for(int i = 1; i <= n; i ++) record[i] += b[u][i];
    dfs(u + 1, cnt + 1);
    for(int i = 1; i <= n; i ++) record[i] -= b[u][i];
    path.pop_back();

    // 不选第u个套餐
    dfs(u + 1, cnt);
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n; j ++) cin >> b[i][j];
    dfs(1, 0);
    cout << number << endl;
    for(auto& id : res) cout << id << ' ';
    return 0;
}

