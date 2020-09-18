#include <iostream>
#include <string>
#include <vector>

using namespace std;
//left와 right는 필요없음 그리고 decode에 s도 들어갈 필요가 없다

void decode(vector<int>& nums, string &sub) {
	string str;
	int num = nums.back();//현재 숫자의 가장 마지막꺼를 넣어준다.(이말은 가장 안쪽에 있는 괄호의 숫자를 뜻한다)
	nums.pop_back();
	string tmp = sub;
	for (int z = 1; z < num; z++) {
		sub += tmp;
	}
}
string solution(string s) {
	if (s.size() > 0) {
		vector<int> nums;
		vector<string> sub;
		sub.push_back("");//초기화
		string num;
		for (int i = 0; i < s.size(); i++) {
			if (isdigit(s[i])) {//숫자인경우에는 숫자 string에 우선 넣어준다.
				num += s[i];
			}
			else if (s[i] == '[') {//왼쪽 괄호 나온경우
				string ss = "";
				nums.push_back(atoi(num.c_str()));//숫자를 stack 구조인 nums vector에 넣는다.
				num = "";
				sub.push_back(ss);//sub string 벡터에 새로운 string을 추가한다.
			}
			else if (s[i] == ']') {//오른쪽 괄호면 하나씩 추가
				decode(nums,sub.back());//decode를 실행한다. =반복해준다. 반복된 string을 sub.back()에 적용
				string ss = sub.back();//반복한 string을 ss에 넣어준다.
				if (sub.size() > 1) {//	sub 괄호가 안에 또 존재하는 경우
					sub.pop_back();//가장 안에있는것부터 pop해준다
					sub.back() += ss;//그다음 안에 있는 것 뒤에 붙여준다.
				}
			}
			else {
				sub.back() += s[i];//괄호가 끝나기 전까지 가장 마지막에 나온 string에 더해준다.
			}
		}
		return sub.back();
	}
	else {
		return "";
	}
}
int main() {
	string s = "3(a2(c))";
	string ans= solution(s);
	cout << ans;
	
}