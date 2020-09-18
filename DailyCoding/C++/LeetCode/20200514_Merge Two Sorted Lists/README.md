# 21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.  

## Example1

```
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
```

## trial1
### Intuition
```
l1과 l2의 첫번째 요소들을 비교해서 작은 값을 nw에 첫번째 요소로 넣는다.
그것을 head로 정해놓고 이제 l1과 l2중 하나라도 NULL이 될때까지 현재 pointer에 대한 값을 비교하여 nw의 다음 값으로 정해준다.
그리고 그 뒤에는 l1과 l2 포인터가 NULL을 아직 가르키지 않는 값들을 nw 뒤에 이어붙어주기를 진행한다.


Compare the first elements of l1 and l2 and put the small value in nw as the first element.
Set it as head, and compare the value of the current pointer until either one of l1 and l2 is NULL, and set it as the next value of nw.
And after that, the l1 and l2 pointers continue to append values ​​that do not yet point to NULL after nw.
```
### Codes  
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * nw;
        ListNode * head=NULL;
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        else {
            if (l1->val < l2->val) {
                nw = l1;
                l1 = l1->next;
            }
            else {
                nw = l2;
                l2 = l2->next;
            }
        }
        head = nw;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                nw->next = l1;
                l1 = l1->next;
            }
            else {
                nw->next = l2;
                l2 = l2->next;
            }
            nw = nw->next;
        }
        while (l1 != NULL) {
            nw->next = l1;
            l1 = l1->next;
            nw = nw->next;
        }
        while (l2 != NULL) {
            nw->next = l2;
            l2 = l2->next;
            nw = nw->next;
        }
        return head;
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