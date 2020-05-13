# 19. Remove Nth Node From End of List  
Given a linked list, remove the n-th node from the end of list and return its head.   
**Note:**
Given n will always be valid.  

**Follow up:**
Could you do this in one pass?  

Linked List와 n이 주어질때 뒤에서 n번째 앞에 있는 node를 지우는 것이 목표이다.  
single pass로 해야한다.   

**Example1:**   
```
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5. 
```

## trial1
### Intuition
```
1.  첫번째 trial은 LisNode의 포인터 vector을 사용한 방법이다.  
(The first trial is using a vector of ListNode's pointer.)  
2.  뒤에서 n번째 숫자의 node의 이전값이 범위를 벗어나지 않는 이상 prev라는 것을 정의하여 n번째 node의 다음과 연결해준다.
( Define the prev and connect it with the next of the nth node from the back as long as the previous value of the nth number node from back is not out of range.)
3.  범위를 벗어나는 경우에는 n번째가 head를 가르키는 경우 혹은 node가 없는 경우를 뜻하므로 첫번째 경우에는 head의 다음 node를 반환하도록 하고 두번째 경우에는 그냥 NULL을 반환하면 된다.
(If it is out of range, the nth node is to head or there is no node List, so in the first case just return the next node of head and in the second case just return NULL.)
```
### Codes  
```cpp
  struct ListNode {
      int val;
	  ListNode *next;
	  ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		vector<ListNode *> node;
		ListNode * cur = head;
		while (cur != NULL) {
			node.push_back(cur);
			cur = cur->next;
		}
		if (node.size() < n + 1) {
			if (node.size() == n) return head->next;
			return NULL;
		}
		ListNode * prev = node[node.size() - n - 1];
		cur = node[node.size() - n];
		prev->next = cur->next;
		return node[0];
	}
};
```

### Results (Performance)  
**Runtime:** 4 ms   
**Memory Usage:** 8.4 MB   

<p align="center"> 
<img src="./capture.png">
</p>


## trial2
### Intuition
```
1.  두번째 trial에서 사용한 방법은 vector의 사용 없이 오직 포인터로만 작동하는 방식이다. 
(The method used in the second trial works only with pointers without the use of vectors.)
2.  str은 start 포인터고 prev는 start의 이전 node의 포인터이다. str은 n번째 node가 가르키는 node가 존재할때부터 움직인다. 
(str is the start pointer and prev is the pointer to the previous node of start. str moves from the node pointed to by the nth node.)
3. 첫번째 while문을 빠져나가게 되면 str이 바로 remove할 node의 포인터를 가르키게 된다.
(When it exits the first while statement, str points to the node pointer would be the one should be removed.)
4.  만약에 start와 prev가 같은 경우에는 head가 가르키는 node가 지워져야 하거나 node가 하나밖에 없는 경우이므로 head를 다음 node를 가르키도록 옮겨주거나 node자체를 지워서 NULL을 반환하게 해야한다.
(If start and prev are the same, the node pointed by head must be deleted or there is only one node in the Linked List, so move the head to point to the next node or delete the node itself to return NULL.)
```
### Codes  
```cpp
  struct ListNode {
      int val;
	  ListNode *next;
	  ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode * cur = head, *str = head,*prev=head;
		while (cur != NULL) {
			if (n <= 0) {//n이 1보다 큰경우
				prev = str;
				str = str->next;
			}
			n--;
			cur = cur->next;
		}
		if (str!=prev)
		{
			prev->next = str->next;
			delete str;
			return head;
		}
		else {//둘이 같은경우
			if (str->next!=NULL) {
				head=prev->next;
				delete prev;
				return head;
			}
			delete str;
			return NULL;
		}
	}
};
```

### Results (Performance)  
**Runtime:** 4 ms   
**Memory Usage:** 8 MB   

<p align="center"> 
<img src="./capture2.JPG">
</p>   

### Discussion
이 링크드 리스트 문제를 두가지의 방법으로 풀어보니 performance의 차이는 그리 크지는 않았지만 다방면으로 공부 할 수 있어서 좋았다.  
I solved this linked list problem in two ways, which was a great experience to build a coding skills. However, the performance of two ways had almost no difference.  

### 문제 URL (LeetCode)  
https://leetcode.com/problems/palindrome-linked-list/
