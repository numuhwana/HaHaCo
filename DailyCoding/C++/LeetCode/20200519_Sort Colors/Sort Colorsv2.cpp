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
        int b=nums.size()-1;
        int f = 0;
        int cur = 0;
        while (b >= cur) {
            if (nums[cur] == 0) {
                swap(nums[f++], nums[cur++]);
            }
            else if (nums[cur] == 2) {
                swap(nums[b--], nums[cur]);
            }
            else cur++;
        }
    }
};
int main() {
    vector<int> n = {
        2,2,1,2,2,1,2,0,0,0,2,1,0
    };
    Solution s = Solution();
    s.sortColors(n);

}