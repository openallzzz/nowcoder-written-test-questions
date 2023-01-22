// 题目链接：https://www.nowcoder.com/questionTerminal/0069dafd4c7640e28b5f339136c11c2d

#define x first
#define y second

class Solution {
public:

    int idx;
    int res = 0;
    unordered_map<string, int> ids;
    unordered_map<int, int> mp;

    PII dfs(TreeNode* root) {
        if(!root) return {0, 0};

        auto l = dfs(root->left);
        auto r = dfs(root->right);

        string key = to_string(root->val) + ' ' + to_string(l.x) + ' ' + to_string(r.x);
        if(ids.count(key) == 0) ids[key] = ++ idx;
        int id = ids[key];

        if(++ mp[id] == 2) res = max(res, l.y + r.y + 1);
        return {id, l.y + r.y + 1};
    }

    int maxSubTree(TreeNode* root) {
        // write code here
        dfs(root);
        return res;
    }
};
