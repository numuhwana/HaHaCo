#include <iostream>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
int bad = 0;
bool isBadVersion(int version) {
	if (version >= bad) return true;
	return false;
}
class Solution {
public:
	int firstBadVersion(int n) {
		if (!isBadVersion(n)) return n;
		int lft=1, rgt=n;
		int p;
		while (lft <= rgt) {
			p = ceil((lft + rgt) / 2);
			if (isBadVersion(p)) {
				rgt = p - 1;
			}
			else {
				lft = p +1;
			}
		}
		return lft;
	}

};	
int main() {
	Solution sol = Solution();
	bad = 6;
	cout<<sol.firstBadVersion(9);
	return 0;
}