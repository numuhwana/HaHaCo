#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class MinStack {
public:
	vector<int> arr;
	priority_queue<int,vector<int>,greater<int>> min;
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		arr.push_back(x);
		min.push(x);
		
	}

	void pop() {
		int tmp = arr.back();
		arr.pop_back();
		priority_queue<int, vector<int>, greater<int>> tmp2;
		bool one = false;
		while (!min.empty()) {
			if (min.top() != tmp || one) {
				tmp2.push(min.top());
				min.pop();
			}
			else {
				one = true;
				min.pop();
			}
		}
		min = tmp2;
	}

	int top() {
		return arr[arr.size()-1];
	}

	int getMin() {
		return min.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
	MinStack *minStack = new MinStack();
	//minStack->push(-2);
	minStack->push(2);
	minStack->push(2);
	minStack->push(3);
	minStack->push(0);
	minStack->push(0);
	minStack->pop();
	minStack->push(-3);
	minStack->getMin();  
	minStack->pop();
	minStack->top();     
	minStack->getMin();
	return 0;
}