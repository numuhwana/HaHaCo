# 215. Kth Largest Element in an Array
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.  

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.  

Note: You are not suppose to use the library's sort function for this problem.

## Example1

```
Input: [3,2,1,5,6,4] and k = 2
Output: 5
```

## Example2

```
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
```

## trial1
### Intuition
```
아래 방법은 모든 nums의 red white blue 값을 세어주는 것이다.
다 세준 후에 한번더 nums의 모든 요소를 방문하여 개수만큼 0과 1과 2를 채워주는 방식이다.


The method below is to count the red white blue values ​​of all nums.
After counting all the numbers of color fill in 0, 1, and 2 in nums.
```
### Codes  
```cpp
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
```

### Results (Performance)  
**Runtime:**  4 ms O(n)  
**Memory Usage:** 	8.4 MB  

<p align="center"> 
<img src="./capture2.JPG">
</p>


## trial2
### Intuition
```
swaping 하는 방식으로 문제를 해결하였다.
현재 인덱스, 처음을 가르키는 인덱스 f 마지막을 가르키는 b 인덱스를 사용하여 문제를 해결하였다.
현재 인덱스의 값이 0이라면 앞에 무조건 들어가야하기 때문에 f인덱스에 넣는다 f는 0이 들어갈때마다 뒤로 밀려난다
만약에 현재 인덱스 값이 2라면 뒤에 인덱스 b와 바꿔준다 하지만 이땐 cur은 ++을 하지 않는다
왜냐하면 현재 인덱스의 값이 바뀐 후에도 2일수 있기 때문이다.
현재 인덱스가 1인경우에는 그냥 넘겨준다. 어차피 뒤에 0이나오더라도 f와 알아서 바뀌기 때문이다.

The problem was solved by swapping.
We solved the problem by using the current index "cur", index "f" pointing to the beginning, and index "b" pointing to the end.
If the value of the current index is 0, it must be entered in front, so "f" is put in the index. "f" plus 1 whenever 0 is entered.
If the current index value is 2, it is replaced with index "b" later, but at this time, cur does not do ++
This is because value of arr[cur] can be 2 after the current index value changes.
If the current index is 1, just pass it. This is because even if it comes after 0 anyway, it changes with f.
```
### Codes  
```cpp
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
```

### Results (Performance)  
**Runtime:**  4 ms O(n)  
**Memory Usage:**  8.6 MB  

<p align="center"> 
<img src="./capture2.JPG">
</p>



### 문제 URL (LeetCode)  
https://leetcode.com/problems/sort-colors/