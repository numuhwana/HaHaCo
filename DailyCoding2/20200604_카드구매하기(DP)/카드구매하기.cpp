#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
int N;
int main() {
	//freopen("카드구매하기.txt", "r", stdin);
	cin >> N;
	vector<int> card;
	vector<int> dp;
	int tmp = 0;
	dp.push_back(0);
	cin >> tmp;
	dp.push_back(tmp);
	int j = 0;
	for (int i = 2; i <= N; i++) {
		cin >> tmp;
		dp.push_back(tmp);
		j = 1;
		while (j <= (i / 2)) {
			dp[i] = max(dp[i],dp[i - j]+dp[j]);
			j++;
		}
	}
	cout << dp[N];
	return 0;
}