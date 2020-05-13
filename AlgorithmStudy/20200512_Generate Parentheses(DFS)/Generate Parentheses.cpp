#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", n, n);
        return res;
    }
    void dfs(vector<string>& res,string cur, int lt, int rt) {
        if (lt > rt) return;
        if (lt == 0 && rt == 0) {
            res.push_back(cur);
            return;
        }
        if (lt > 0) {
            cur += "(";
            dfs(res, cur, lt - 1, rt);
            cur.pop_back();
        }
        if (rt > 0) {
            cur += ")";
            dfs(res, cur, lt, rt - 1);
            cur.pop_back();
        }
    }
};
int main() {
    Solution sol = Solution();
    sol.generateParenthesis(3);
}