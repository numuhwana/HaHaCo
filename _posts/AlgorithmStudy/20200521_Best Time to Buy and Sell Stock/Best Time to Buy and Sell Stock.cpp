#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);
    }
    int maxProfit(vector<int>& p) {
        if (p.size() == 0) return 0;
        int cursm = p[0],diff=0;

        for (int i = 1; i < p.size(); i++) {
            if (cursm < p[i]) {
                diff=max(p[i] - cursm,diff);//diff가 가장 큰것 가져오기
            }
            else if (cursm > p[i]) {
                cursm = p[i];//가장 작은값으로 업데이트
            }
        }
        return diff;
    }
};
int main() {
    Solution s = Solution();
    vector<int> a = { 7,1,5,3,6,4 };
    cout<<s.maxProfit(a);
    return 0;
}