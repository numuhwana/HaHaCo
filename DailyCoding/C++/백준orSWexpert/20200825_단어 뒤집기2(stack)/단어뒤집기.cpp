#include <iostream>
#include <vector>
#include <string>
#pragma warning (disable:4996)
using namespace std;
int main() {
	//freopen("단어뒤집기2.txt", "r", stdin);
	string str,tmp="",ans;
	getline(cin, str);
	bool par = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '<') {//괄호면 queue에 넣기
			par = true;
			while (tmp.size() > 0) {
				char c = tmp.back();
				tmp.pop_back();
				ans.push_back(c);
			}
		}
		if (par) {
			ans.push_back(str[i]);
			if (str[i] == '>') {//뒷괄호면
				par = false;
			}
		}
		else {
			if (str[i] == ' ') {
				while (tmp.size() > 0) {
					char c = tmp.back();
					tmp.pop_back();
					ans.push_back(c);
				}
				ans.push_back(str[i]);
			}
			else {
				tmp.push_back(str[i]);
			}
		}
	}
	while (tmp.size() > 0) {
		char c = tmp.back();
		tmp.pop_back();
		ans.push_back(c);
	}
	cout << ans << endl;
	return 0;
}