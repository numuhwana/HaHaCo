#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canConstruct(string r, string mag) {
        int arr[26] = { 0, };
        for (int i = 0; i < r.size(); i++) {
            arr[r[i]-97]++;
        }
        for (int i = 0; i < mag.size(); i++) {
            arr[mag[i] - 97]--;
        }
        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) return false;
        }
        
        return true;
    }
};
int main() {
    Solution sol = Solution();
    string r="a";
    string m = "b";
    cout<<(sol.canConstruct(r, m)?"True":"false");
    return 0;
}