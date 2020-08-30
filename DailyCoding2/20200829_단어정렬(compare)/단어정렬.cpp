#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
bool compare(const string a, const string b) {
	if (a.size() != b.size()) {//문자열 개수 다르면 작은거 우선
		return a.size() < b.size();
	}
	else {
		return a < b;
	}
}
int main() {
	int N;
	vector<string> s;
	freopen("단어정렬.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		s.push_back(tmp);
	}
	sort(s.begin(), s.end(),compare);
	string prev = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != prev) {
			cout << s[i] << endl;
			prev = s[i];
		}
	}
	return 0;
}