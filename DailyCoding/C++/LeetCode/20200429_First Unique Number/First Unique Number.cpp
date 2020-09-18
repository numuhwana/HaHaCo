#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
class FirstUnique {
public:
	unordered_map<int, int> a;
	queue<int> q;
	FirstUnique(vector<int>& nums) {
		for (int i = 0; i < nums.size();i++) {
			a[nums[i]]++;
			q.push(nums[i]);
		}
	}

	int showFirstUnique() {
		int i = -1;
		while (!q.empty()) {
			i = q.front();
			if (a[i] > 1) {
				q.pop();
			}
			else if (a[i] == 1) {
				return i;
			}
		}
		return -1;
	}

	void add(int value) {
		if(a[value]++==0)
			q.push(value);
	}
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
int main() {
	return 0;
}