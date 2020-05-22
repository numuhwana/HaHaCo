#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int lt = 0, rt = nums.size() - 1;
        int st=0, lst=rt;
        int pv = 0;
        while (lt < rt) {
            pv = (lt + rt) / 2;
            if (nums[pv] < target) {
                lt = pv + 1;
            }
            else if (nums[pv] > target) {
                rt = pv;
            }
            else {//같은경우 target의 시작점을 찾아야한다.
                while (nums[lt]!=target) {
                    lt = ((pv + lt) / 2)+1;//lt는 무조건 target보다 작은경우만 있음
                }
                while (nums[rt] != target) {
                    rt = ((pv + lt) / 2);//lt는 무조건 target보다 큰경우만 있음
                }
                while (lt >= 0) {
                    if (nums[lt] != target) {
                        break;
                    }
                    lt--;
                }
                st = lt + 1;
                while (rt < nums.size()) {
                    if (nums[rt] != target) {
                        break;
                    }
                    rt++;
                }
                lst = rt - 1;
                break;
            }
        }
        if (lt >= rt) {
            if (lt == rt && nums[lt]==target) {
                res.push_back(lt);
                res.push_back(rt);
                return res;
            }
            res.push_back(-1);
            res.push_back(-1);
        }
        else {
            res.push_back(st);
            res.push_back(lst);
        }
        return res;
    }
};
void print(vector<int> a) {
    cout << a[0] << " " << a[1] << endl;
}
int main() {
    vector<int> n = {
        6,6,8,9,10
    };
    int t = 6;
    Solution s = Solution();
    print(s.searchRange(n, t));
    return 0;
}