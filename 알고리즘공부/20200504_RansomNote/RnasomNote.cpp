#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canConstruct(string r, string mag) {
        unordered_map<char, int> m;
        for (int i = 0; i < r.size(); i++) {
            m[r[i]]++;
        }
        for (int i = 0; i < mag.size(); i++) {
            if (m.find(mag[i]) != m.end()) {
                m[mag[i]]--;
            }
        }
        for (int i = 0; i < m.size(); i++) {
            if (m[i] > 0) return false;
        }
        return true;
    }
};
int main() {
    Solution sol = Solution();
    string r="fffbfg";
    string m = "effjfggbffjdgbjjhhdegh";
    cout<<(sol.canConstruct(r, m)?"True":"false");
    return 0;
}