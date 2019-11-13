#include<cstdio>
#include<vector>
using namespace std;

//解法一
//class Solution {
//public:
//	int lengthOfLIS(vector<int>& nums) {
//		if (nums.size() == 0) {
//			return 0;
//		}
//		vector<int> dp(nums.size(), 0);
//		dp[0] = 1;
//		int LIS = 1;
//		for (int i = 1; i < dp.size(); i++) {
//			dp[i] = 1;
//			for (int j = 0; j < i; j++) {
//				if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {	//最长上升子序列，严格递增
//					dp[i] = dp[j] + 1;
//				}
//			}
//			if (LIS < dp[i]) {
//				LIS = dp[i];
//			}
//		}
//		return LIS;
//	}
//};

//解法二
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		vector<int> stack;
		stack.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > stack.back()) {
				stack.push_back(nums[i]);
			}
			else {
				/*for (int j = 0; j < stack.size(); j++) {
					if (stack[j] >= nums[i]) {
						stack[j] = nums[i];
						break;
					}
				}*/
				int pos = binary_search(stack, nums[i]);	//优化查找应该替换的位置
				stack[pos] = nums[i];
			}
		}
		return stack.size();
	}
	int binary_search(vector<int> nums, int target) {
		int index = -1;
		int begin = 0;
		int end = nums.size() - 1;
		while (index == -1) {
			int mid = (begin + end) / 2;
			if (target == nums[mid]) {
				index = mid;
			}
			else if (target < nums[mid]) {
				if (mid == 0 || target > nums[mid - 1]) {
					index = mid;
				}
				end = mid - 1;
			}
			else if (target > nums[mid]) {
				if (mid == nums.size() - 1 || target < nums[mid + 1]) {
					index = mid + 1;
				}
				begin = mid + 1;
			}
		}
		return index;
	}
};

int main() {

	int test[] = { 1,3,2,3,1,4 };
	vector<int> nums;
	for (int i = 0; i < 6; i++) {
		nums.push_back(test[i]);
	}
	Solution solve;
	printf("%d\n", solve.lengthOfLIS(nums));

	return 0;
}