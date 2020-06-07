#include <iostream>
#include <vector>
#include <string>
#include <map>
#pragma warning (disable:4996)
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int L, R,T;
	//freopen("개미.txt", "r", stdin);
	cin >> L >> R;
	vector<char> LL,RR;//각 group에 대한 배열
	vector<char> ans(L+R);
	map<char, int> m;
	char tmp;
	for (int i = L - 1; i >= 0; i--) {//map에 L에 대한 인덱스 넣기
		cin>>tmp;
		m[tmp] = i;
		LL.push_back(tmp);
	}
	for (int i = L; i < L + R; i++) {//map에 R에 대한 인덱스 넣기
		cin >> tmp;
		m[tmp] = i;
		RR.push_back(tmp);
	}
	cin >> T;//시간 받기
	for (int i = 1; i <= T; i++) {//시간만큼 돌리기
		for (int j = 0; j < i; j++) {//초만큼 움직임이 시작됨
			//범위 안에 있을때만 움직임
			if((i-R)<=j && j<L) m[LL[j]]++; //L은 R의 개수만큼 더 움직여야 해서 i초-R보다 큰 인덱스만 한다.
			if((i-L)<=j && j<R) m[RR[j]]--;//R은 L의 개수만큼 더 움직여야 하니까 i-L보다 큰 인덱스만 움직인다.
		}
	}
	for (auto it : m) {//ans 배열에 값들 다 집어넣기
		ans[it.second] = it.first;
	}
	for (char s : ans) {//출력
		cout << s;
	}
	return 0;
}