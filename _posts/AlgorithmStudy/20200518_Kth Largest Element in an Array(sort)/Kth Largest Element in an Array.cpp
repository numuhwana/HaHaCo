class Solution {
public:
    Solution() { ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); }
    int findKthLargest(vector<int>& n, int k) {
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < n.size(); i++) {
            q.push(n[i]);
        }
        for (int i = 1; i < k; i++) {
            q.pop();
        }
        return q.top();
    }
};