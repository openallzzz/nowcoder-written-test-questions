// 题目链接：https://www.nowcoder.com/questionTerminal/f174bbbd98284447b8d12791f602472e
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a int整型vector 
     * @param t int整型 
     * @return long长整型
     */

    typedef long long LL;
    long long section(vector<int>& a, int t) {
        // write code here
        LL res = 0;
        int n = a.size(), L = 0;
        unordered_map<int, int> cnt;
        for(int i = 0; i < a.size(); i ++) {
            if(cnt.count(a[i])) {
                L = max(L, cnt[a[i]] + 1);
            }
            res = res + 0ll + i - L;
            cnt[a[i] ^ t] = i;
        }
        return res;
    }
};
