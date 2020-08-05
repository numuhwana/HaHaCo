#include <iostream>
#include <vector>
#include <map>
#pragma warning (disable:4996)
using namespace std;
map<int, bool> m;
void function(vector<int> &v,int& n,vector<int>& v2,int cur) {
	if (v2.size() == n) {
		int sum = 0;
		for (int i : v2) {
			sum += i;
		}
		if (m.find(sum) == m.end()) {
			m[sum] = true;
		}
	}
	else {
		if (cur == v.size()) return;
		v2.push_back(0);
		function(v, n, v2, cur + 1);
		v2.pop_back();
		v2.push_back(v[cur]);
		function(v, n, v2, cur + 1);
		v2.pop_back();

	}
}
int main() {
	//freopen("sample_input.txt", "r", stdin);
	int tc = 0;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n = 0;
		cin >> n;
		vector<int> v(n, 0);//각 문제의 배점
		vector<int> v2;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			v[i]=tmp;
		}
		function(v, n, v2, 0);
		cout << '#'<<t+1<<" "<<m.size()<<endl;
		m.clear();
	}
	return 0;
}