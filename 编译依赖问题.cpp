// https://www.nowcoder.com/questionTerminal/74d0c1b6bb5a403a84093d0ffdc58ee2

#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e5 + 10;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 编译顺序
     * @param input string字符串 
     * @return string字符串
     */
    string compileSeq(string input) {
        input.push_back(',');

        vector<int> t;
        int flag = 1;
        for(int i = 0, x = 0; i < input.size(); i ++) {
            char c = input[i];
            if(c == ',') t.push_back(x * flag), x = 0, flag = 1;
            else if(c != '-') x = x * 10 + (c - '0');
            else if(c == '-') flag = -1;
        }

        map<int, set<int>> g;
        vector<int> ind(t.size());
        vector<bool> st(t.size());
        for(int i = 0; i < t.size(); i ++) {
            int x = i, y = t[i]; 
            if(y != -1) {
                g[y].insert(x);
                ind[x] ++ ;
            }
        }

        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < ind.size(); i ++) {
            if(ind[i] == 0) {
                q.push(i);
                st[i] = true;
            }
        }

        string res;
        while(q.size()) {
            auto t = q.top(); q.pop();
            res += "," + to_string(t);
            for(auto& ne : g[t]) {
                if(!st[ne]) {
                    q.push(ne);
                    st[ne] = true;
                }
            }
        }

        return res.substr(1);
    }
};

void solve() {
    
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

