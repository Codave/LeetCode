#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//解法一
//class Solution {
//public:
//	int trap(vector<int>& height) {
//		stack<int> st;
//		int i = 0;
//		int n = height.size();
//		int res = 0;
//		while(i<n){
//			if (st.empty() || height[i] <= height[st.top()]) {
//				st.push(i++);   
//			}else{    //height[st.top()] < height[i]
//				int t = st.top();
//				st.pop();
//				if (st.empty()) continue;
//				res += (min(height[i],height[st.top()]) - height[t]) * (i - 1 - st.top());
//			}
//		}
//		return res;
//	}
//};

//解法二
//class Solution {
//public:
//	int trap(vector<int>& height)
//	{
//		if (height.empty()) return 0;
//		int ans = 0;
//		int n = height.size();
//		vector<int> left_max(n), right_max(n);
//		left_max[0] = height[0];
//		for (int i = 1; i < n; i++) {
//			left_max[i] = max(height[i], left_max[i - 1]);
//		}
//		right_max[n - 1] = height[n - 1];
//		for (int i = n - 2; i >= 0; i--) {
//			right_max[i] = max(height[i], right_max[i + 1]);
//		}
//		for (int i = 1; i < n - 1; i++) {
//			ans += min(left_max[i], right_max[i]) - height[i];
//		}
//		return ans;
//	}
//};

//解法三
class Solution {
public:
	int trap(vector<int>& height)
	{
		int res = 0;
		stack<int> st;
		for (int i = 0; i < height.size(); i++) {
			int last = 0;
			while (st.size() && height[st.top()] <= height[i]) {
				int t = st.top();
				st.pop();
				res += (i - 1 - t) * (height[t] - last);
				last = height[t];
			}
			if (st.size()) res += (i - 1 - st.top()) * (height[i] - last);
			st.push(i);
		}
		return res;
	}
};

int main() {
	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int res = Solution().trap(height);
	cout << res << endl;

	return 0;
}