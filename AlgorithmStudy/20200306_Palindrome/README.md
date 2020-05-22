# 234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.  

**Follow up:**  
Could you do it in O(n) time and O(1) space?   

palindrome 이란 앞 뒤가 대칭적으로 같은 문자열을 뜻한다. 주어진 LinkedList가 palindrome인지 아닌지를 판단하는 문제이다.    
시간은 O(n) 그리고 space는 O(1)로 할 수 있는지에 대한 부가적인 문제도 있다.  

**Example1:**   
```
Input: 1->2  
Output: false  
```

**Example1:**   
```
Input: 1->2->2->1  
Output: true  
```

## trial1
### Intuition
```
1.  제일 먼저 든 생각은 stack이었다. 하지만 vector을 사용하게 되면 메모리 사용량이 O(n)이 된다. 밑의 코드는 vector을 사용한 코드이다. 
(The first thought was to use stack. But when I use a vector, the memory usage will O (n). I used vector for the code under.)
2.  처음 내가 해야 했던 것은 ListNode의 총 개수를 세는 것이었다.
(First thing I had to do is to count a number of ListNode.)
3.  vector에 있는 값을 pop_back을 해주면서 ListNode의 중간값부터 서로 값이 같은지 확인한다.
(I Compared two numbers that are from vector popped back and from middle of ListNode.) 
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
	bool isPalindrome(ListNode* head) {
		vector<int> arr;
		ListNode * cur = head;
		int cnt = 0,cnt2=0;
		while (cur != NULL) {
			cnt++;
			arr.push_back(cur->val);
			cur = cur->next;
		}
		cur = head;
		while (cur != NULL) {
			cnt2++;
			if (cnt2 == floor(cnt / 2) + 1) return true;
			if (cur->val != arr.back()) return false;
			arr.pop_back();
			cur = cur->next;
		}
	}
};
```

### Results (Performance)  
**Runtime:** 24 ms   
**Memory Usage:** 12.7 MB   

<p align="center"> 
<img src="./capture.JPG">
</p>  

### Discussion
trial1에서의 방법은 O(2n)이므로 O(n)이 된다. 하지만 vector을 사용하면서 ListNode안에 있는 모든 Node들을 담아야 했기 때문에 O(n)이 되어 버렸다.   

(In trial1, a speed is O(2n) which equals O(n). However for memory usage, I had to insert every Node into stack, so it became O(n). )  

### 문제 URL (LeetCode)  
https://leetcode.com/problems/palindrome-linked-list/
