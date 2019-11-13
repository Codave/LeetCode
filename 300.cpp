#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		vector<int> dp(nums.size(), 0);
		dp[0] = 1;
		int LIS = 1;
		for (int i = 1; i < dp.size(); i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {	//最长上升子序列，严格递增
					dp[i] = dp[j] + 1;
				}
			}
			if (LIS < dp[i]) {
				LIS = dp[i];
			}
		}
		return LIS;
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