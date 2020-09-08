#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#pragma warning (disable:4996)
using namespace std;
vector<int> v;
bool ispalin(int a) {//팔린드롬인지 확인
	string s = to_string(a);
	for (int i = 0; i < s.size()/2; i++) {
		if (s[i] != s[s.size() - i - 1]) return false;
	}
	return true;
}
void isPrime(int a) {//에라토스의체 알고리즘 사용
	for (int i = 0; i <= a; i++) {
		v.push_back(i);
	}
	for (int i = 2; i <= sqrt(a) && v[a]>0; i++) {//a의 제곱근까지만 진행 제곱근 이후로는 
		if (v[i] != 0) {//이미 체크되지 않은경우
			for (int j = i+i; j <= a; j += i) {//배수인 애들 모두 0으로 표시
				v[j] = 0;
			}
		}
	}
}
int main() {
	freopen("소수와팰린드럼.txt", "r", stdin);
	int N;
	cin >> N;
	int i = N;
	if (i == 1) {
		i++;
	}
	else {
		isPrime(1003001);
		while (i <= 1003001) {
			if (v[i] > 0) {
				if (ispalin(i)) {//팔린드롬인지 확인
					break;
				}
			}
			i++;
		}
	}
	cout << i << endl;
	return 0;
}