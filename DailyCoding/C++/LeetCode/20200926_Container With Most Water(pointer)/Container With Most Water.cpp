#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
	int lft = 0, rt = height.size() - 1;
	int mx = 0;
	while (lft < rt) {
		int h = (height[lft] < height[rt] ? height[lft] : height[rt]);
		int nw = h * (rt - lft);
		(height[lft] > height[rt] ? rt-- : lft++);
		mx = max(mx, nw);
	}
	return mx;
}
int main()
{
	vector<int> histogram = { 1,8,6,2,5,4,8,3,7 };
	maxArea(histogram);
	return 0;
}