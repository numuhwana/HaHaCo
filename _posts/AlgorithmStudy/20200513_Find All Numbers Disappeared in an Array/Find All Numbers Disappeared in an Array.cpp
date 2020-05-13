#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if (nums.size() <= 0) return res;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums[0]; i++) {
            res.push_back(i);
        }
        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = 1; j < (nums[i + 1] - nums[i]); j++) {
                res.push_back(nums[i] + j);
            }           
        }
        for (int i = nums[nums.size()-1]+1; i <= nums.size(); i++) {
            res.push_back(i);
        }
        return res;
    }
};

void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }cout << endl;
}
int main() {
    Solution sol = Solution();
    vector<int> a = {
        5,4,6,7,9,3,10,9,5,6
    };
    print(sol.findDisappearedNumbers(a));
    return 0;

}