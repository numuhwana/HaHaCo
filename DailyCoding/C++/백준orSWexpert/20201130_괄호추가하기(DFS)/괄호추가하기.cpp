#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h> //INT_MIN
#pragma warning(disable:4996)
using namespace std;
vector<int> nv;
vector<char> ov;
vector<bool> visit;
int n;
long ans = INT_MIN;
long cal(long a, long b, char op) {
	int res = 0;
	switch (op) {
	case '*':
		res = a * b;
		break;
	case '+':
		res = a + b;
		break;
	case '-':
		res = a - b;
		break;
	}
	return res;
}
void dfs(long cur,int idx) {
	if (idx == ov.size()) {//모든 operation을 완료한경우
		ans = max(cur, ans);
	}
	else {
		//다음 연산을 괄호로 먼저 계산하는 경우
		if (idx < ov.size() - 1) {
			long nxt = cal(nv[idx + 1], nv[idx + 2], ov[idx + 1]);
			dfs(cal(cur, nxt,ov[idx]), idx + 2);
		}
		//현재 연산을 괄호를 하지 않고 계산하는 경우
		dfs(cal(cur, nv[idx + 1], ov[idx]), idx + 1);
	}
}
int main() {
	freopen("괄호추가하기2.txt", "r", stdin);
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			nv.push_back(atoi(&s[i]));
		}
		else {
			visit.push_back(false);
			ov.push_back(s[i]);
		}
	}
	dfs(nv[0],0);
	cout << ans;
	return 0;
}