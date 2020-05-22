#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int lengthOfLongestSubstring(string s) {
        map<char,int> let;
        int local=1;
        int st = 0;
        if (s.size() == 0) return 0;
        let[s[0]]++;
        for (int i = 1; i < s.size(); i++) {
            if (let[s[i]]>0) {
                while (st < i) {
                    let[s[st]]--;
                    st++;
                    if (let[s[i]]==0) {
                        break;
                    }
                }
                let[s[i]]++;
            }
            else {
                let[s[i]]++;
            }
            if ((i - st + 1) > local) local = i - st + 1;
        }
        return local;
    }
};
int main() {
    string s = "pwwkew";
    Solution ss = Solution();
    cout<<ss.lengthOfLongestSubstring(s);
    return 0;
}