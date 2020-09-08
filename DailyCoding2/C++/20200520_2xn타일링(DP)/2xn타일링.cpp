#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> v;
	int n = 0;
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	for (int i = 3; i <= n; i++) {
		v.push_back((v[i - 1] + v[i - 2])%10007);
	}
	cout << v[n];
	return 0;
}