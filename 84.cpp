#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//解法一
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> st;
		heights.push_back(0);
		int n = heights.size();
		int res = 0;
		for (int i = 0; i < n; ++i) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				int cur = st.top();
				st.pop();
				res = max(res, heights[cur] * (st.empty() ? i : (i - 1 - st.top())));
			}
			st.push(i);
		}
		return res;
	}
};

//解法二
//class Solution {
//public:
//	int largestRectangleArea(vector<int>& height) {
//		int n = height.size();
//		if (n == 0) {
//			return 0;
//		}
//		//求每个柱子的左边的第一个小的柱子的下标
//		vector<int> leftlessmin(n, -1);
//		for (int i = 1; i < n; i++) {
//			int l = i - 1;
//			while (l >= 0 && height[l] >= height[i]) {
//				l = leftlessmin[l];
//			}
//			leftlessmin[i] = l;
//		}
//		//求每个柱子的右边的第一个小的柱子的下标
//		vector<int> rightlessmin(n, n);
//		for (int i = n - 2; i >= 0; i--) {
//			int r = i + 1;
//			while (r <= n - 1 && height[r] >= height[i]) {
//				r = rightlessmin[r];
//			}
//			rightlessmin[i] = r;
//		}
//		int maxArea = 0;
//		for (int i = 0; i < n; i++) {
//			int area = (rightlessmin[i] - leftlessmin[i] - 1) * height[i];
//			maxArea = max(area, maxArea);
//		}
//		return maxArea;
//	}
//};

int main() {
	vector<int> height = { 2,1,5,6,2,3 };
	int res = Solution().largestRectangleArea(height);
	cout << res << endl;

	return 0;
}