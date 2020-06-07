#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	vector<int> dp;
	dp.push_back(0);
	dp.push_back(1);
	dp.push_back(3);
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		dp.push_back((dp[i - 1] + (2 * dp[i - 2]))%10007);
	}
	cout << dp[n];
	return 0;
}