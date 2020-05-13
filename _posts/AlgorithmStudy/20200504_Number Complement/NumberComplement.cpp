#include <iostream>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
        int cnt = 0;
        int tmp = num;
        while (tmp != 0) {
            cnt++;
            tmp = tmp >>1;
        }
        tmp = num << (32 - cnt);
        tmp = (~tmp)>>(32-cnt);
        return tmp;
    }
};
int main() {
    Solution sol = Solution();
    cout << sol.findComplement(5);
    return 0;
}