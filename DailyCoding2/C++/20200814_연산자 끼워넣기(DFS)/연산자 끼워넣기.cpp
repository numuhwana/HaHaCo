/*#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
int mn = 1000000001, mx = -1000000000;
//operation 0:+ 1:- 2:* 3:/
static vector<int> op;
static vector<int> num;
void function(vector<int> &all) {
	if (num.size() == (all.size() + 1)) {//operation의 경우의수
		int res = num[0];
		for (int i = 1; i < num.size(); i++) {
			switch (all[i - 1]) {
			case 0:
				res += num[i];
				break;
			case 1:
				res -= num[i];
				break;
			case 2:
				res *= num[i];
				break;
			case 3:
				res /= num[i];
				break;
			}
		}
		mn = min(mn, res);
		mx = max(mx, res);
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (op[i] > 0) {
				op[i]--;
				all.push_back(i);
				function(all);
				all.pop_back();
				op[i]++;
			}
		}
	}
}
int main() {
	freopen("연산자끼워넣기.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		op.push_back(tmp);
	}
	vector<int> all;
	function(all);
	cout << mx << endl << mn;

}*/