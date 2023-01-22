// 题目链接：https://www.nowcoder.com/questionTerminal/86a27471088249b99d1e9ad23ee04a60?toCommentId=15221136

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @param k int整型 
     * @return string字符串
     */
    string NS_String(string s, int k) {
        // write code here
        int cnt[26] = {0};
        for(auto& c : s) cnt[c - 'a'] ++ ;

        int n = 0;
        for(int i = 0; i < 26; i ++) if(cnt[i]) n ++ ;

        k = min(k, n);

        for(int i = 0, c = 0; i < 26; i ++) {
            if(c == k) break;
            if(cnt[i]) c ++, cnt[i] = 0;
        }

        string res;
        for(auto& c : s) {
            if(cnt[c - 'a']) res += c;
        }

        return res;
    }
};