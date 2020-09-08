#include <iostream>
#include <deque>
#include <string>
#pragma warning (disable:4996)
using namespace std;
class deque2 {
private:
	deque<int> d;
public:
	deque2() {
	}
	void push_front(int a) {
		d.push_front(a);
	}
	void push_back(int a) {
		d.push_back(a);
	}
	int pop_front(){
		if (d.empty()) return -1;
		int front = d.front();
		d.pop_front();
		return front;
	}
	int pop_back(){
		if (d.empty()) return -1;
		int back = d.back();
		d.pop_back();
		return back;
	}
	int size(){
		return d.size();
	}
	int empty(){
		return d.empty();
	}
	int front(){
		if (d.empty()) return -1;
		return d.front();
	}
	int back(){
		if (d.empty()) return -1;
		return d.back();
	}
};
int main() {
	freopen("덱.txt", "r", stdin);
	int N;
	cin >> N;
	deque2 de;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		//cout << s<<": ";
		if(s=="push_front"){
			int X;
			cin >> X;
			de.push_front(X);
		}
		else if (s == "push_back") {
			int X;
			cin >> X;
			de.push_back(X);
		}
		else if (s == "pop_front") {
			cout <<de.pop_front() << endl;
		}
		else if (s == "pop_back") {
			cout << de.pop_back() << endl;
		}
		else if (s == "size") {
			cout << de.size() << endl;
		}
		else if (s == "empty") {
			cout << de.empty() << endl;
		}
		else if (s == "front") {
			cout << de.front() << endl;
		}
		else if (s == "back") {
			cout << de.back() << endl;
		}//cout << endl;
	}
	return 0;
}