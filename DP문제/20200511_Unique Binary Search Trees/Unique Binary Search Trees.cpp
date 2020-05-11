#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> a;
        a.push_back(1);
        a.push_back(1);
        int half = 0;
        int tmp = 0;
        int i = 0;
        for(int cnt=2;cnt<=n;cnt++){
            tmp = 0;
            half = cnt / 2;
            for (i = 0; i < half; i++) {
                tmp += a[i] * a[(cnt - (i+1))];
            }
            tmp *= 2;
            if (cnt % 2 == 1) {//가운데꺼 한번더
                tmp += a[i] * a[i];
            }
            a.push_back(tmp);
        }
        return a[n];
    }
};
int main() {
    Solution sol = Solution();
    cout << sol.numTrees(5);
    return 0;

}