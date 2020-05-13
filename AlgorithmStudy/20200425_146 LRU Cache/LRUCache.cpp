#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;
class LRUCache {
public:
	int cap = 0;
	int sq = 0;
	map<int, pair<int,int>> k;
	map<int, int> s;
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (k.find(key) == k.end()) return -1;
		int bv = k[key].second;
		int bs = k[key].first;
		k[key].first = sq;
		s.erase(bs);
		s[sq++] = key;
		return bv;
	}

	void put(int key, int value) {
		if (k.find(key) != k.end()) {//존재하는경우
			int ss = k[key].first;
			s.erase(ss);
		}
		k[key] = make_pair(sq,value);
		s[sq++] = key;
		if (k.size() > cap) {
			auto it = s.begin();
			int erk = it->second;
			int ers = it->first;
			k.erase(erk);
			s.erase(ers);
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
	LRUCache cache = LRUCache(2 /* capacity */);
	/*cache.put(2,1);
	cache.put(1,1);
	cache.put(2, 3);
	cache.put(4, 1);
	cout << cache.get(1)<<endl;
	cout << cache.get(2) << endl;
	cout << cache.get(4) << endl;*/
	cache.put(1, 1);
	cache.put(2, 2);
	cout<<cache.get(1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	cout<<cache.get(2);       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cout<<cache.get(1);       // returns -1 (not found)
	cout<<cache.get(3);       // returns 3
	cout<<cache.get(4);       // returns 4
	
	return 0;
}