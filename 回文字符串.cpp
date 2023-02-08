// https://www.nowcoder.com/questionTerminal/1e83935468034136b201760128e49fa7

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i ++) {
        bool flag = true;
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(l == i) l ++ ;
            if(r == i) r -- ;

            if(l < r) {
                if(s[l] == s[r]) l ++ , r -- ;
                else {
                    flag = false;
                    break;
                }
            }
        }

        if(flag && l >= r) {
            for(int k = 0; k < s.size(); k ++) {
                if(k == i) continue;
                cout << s[k];
            }
            return 0;
        }
    }

    cout << "false" << "\n";
    return 0;
}