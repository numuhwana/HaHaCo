#include <iostream>
#include <string>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int main() {
	//freopen("문자열.txt", "r", stdin);
	string a, b;
	cin >> a;
	cin >> b;
	int cnt = 0;
	int mcnt = 0;
	int dif = b.size() - a.size();
	for (int i = 0; i <= dif; i++) {
		cnt = 0;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == b[i+j]) {//같다면
				cnt++;
			}
		}
		mcnt = max(mcnt, cnt);
	}
	cout << b.size()-mcnt-dif;
}