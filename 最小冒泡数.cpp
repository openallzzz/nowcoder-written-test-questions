#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, k;
    cin >> t;
    while(t --) {
        cin >> n >> k;
        string t = to_string(n);
        int len = t.size();
        for(int i = 0; i < len && k > 0; i ++) {
            int ne = i + 1, idx = i;
            char cur = t[i];
            while(ne < len && ne <= i + k) {
                if(t[ne] < cur && (t[ne] != '0' || i != 0)) {
                    cur = t[ne], idx = ne;
                }
                ne ++ ;
            }
            k -= idx - i;
            char val = t[idx];
            for(int j = idx; j >= i + 1; j --) t[j] = t[j - 1];
            t[i] = val;
        }
        cout << t << endl;
    }
    return 0;
}