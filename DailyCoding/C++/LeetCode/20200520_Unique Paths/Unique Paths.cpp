#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = 0;
        int i = 0;
        for (; i < nums.size(); i++) {
            if (!nums[i]) r++;
            else if (nums[i] == 1) w++;
            else b++;
        }
        i = 0;
        while (r > 0) {
            nums[i] = 0;
            r--; i++;
        }
        while (w > 0) {
            nums[i] = 1;
            w--; i++;
        }
        while (b > 0) {
            nums[i] = 2;
            b--; i++;
        }
    }
};
int main() {
    vector<int> n = {
        2,0,2,1,1,0
    };
    Solution s = Solution();

}