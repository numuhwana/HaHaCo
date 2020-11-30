#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int main() {
	//freopen("잃어버린괄호.txt", "r", stdin);
	string s;
	cin >> s;
	int ans = 0;
	vector<int> nv;
	vector<char> ov;
	for (int i = 0; i < s.size(); i++) {
		//숫자가 이어질때까지
		string num;
		while (i<s.size() && s[i] >= '0' && s[i] <= '9') {
			num.push_back(s[i]);
			i++;
		}
		nv.push_back(stoi(num));//숫자 넣기
		if (i >= s.size()) break;
		ov.push_back(s[i]);
	}
	int i = 0;
	ans = nv[0];
	while (i<ov.size() && ov[i] == '+') {
		ans += nv[i + 1];
		i++;
	}
	for (; i < ov.size(); i++) {
		ans -= nv[i + 1];
	}
	cout << ans;
}