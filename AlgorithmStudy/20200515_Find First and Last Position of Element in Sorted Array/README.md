# 34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.  

Your algorithm's runtime complexity must be in the order of O(log n).  

If the target is not found in the array, return [-1, -1].  

## Example1

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

## Example2

```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

## trial1
### Intuition
```
Binary serach로 pivot값을 계속 정해서 target에 해당하는 인덱스 값을 찾아준다.
그 후에 target값의 시작과 끝이 어디에 있는지 확인해보아야 한다.
lt와 rt가 target값과 같아질때까지 Binary search를 진행한다.
그 후에는 1씩 증가시키거나 감소시켜서 시작값과 끝나는 값을 찾는다.


Continue to set the pivot value with the binary serach to find the index value corresponding to the target.
After that, we need to check where the start and end values ​​of the target are.
Binary search is performed until lt and rt are equal to the target value.
After that, increment or decrement by 1 to find the start and end values.
```
### Codes  
```cpp
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
```

### Results (Performance)  
**Runtime:**  4 ms  
**Memory Usage:** 	14.4 MB  


<p align="center"> 
<img src="./capture.JPG">
</p>



### 문제 URL (LeetCode)  
https://leetcode.com/problems/merge-two-sorted-lists/