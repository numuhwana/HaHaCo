#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
int main() {
	freopen("스티커.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int s;
		cin >> s;
		vector<vector<int>> v;
		vector<vector<int>> dp(2,vector<int>(s+1,0));
		for (int j = 0; j < 2; j++) {
			vector<int> tmp;
			for (int i = 0; i < s; i++) {
				int tmp2;
				cin >> tmp2;
				tmp.push_back(tmp2);
			}
			v.push_back(tmp);
		}
		dp[0][1] = v[0][0];
		dp[1][1] = v[1][0];
		for (int z = 2; z <= s; z++)//dp 위주
		{
			for (int x = 0; x < 2; x++) {//첫번째의 위아래 모두 돌려주기
				dp[x][z] = max(dp[!x][z - 1], dp[!x][z - 2]) + v[x][z - 1];
			}
		}
		cout << max(dp[1][s], dp[0][s])<<endl;
	}
	return 0;
}