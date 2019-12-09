#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

//解法一
class Solution {
private:
	vector<int> memo;//memo[i]表示考虑抢劫nums[i...n)所能获得的最大收益
	int tryRob(vector<int>& nums, int index) {
		if (index >= nums.size()) {
			return 0;
		}
		if (memo[index] != -1) {
			return memo[index];
		}
		int res = 0;
		for (int i = index; i < nums.size(); i++) {
			res = max(res, nums[i] + tryRob(nums, i + 2));
		}
		memo[index] = res;
		return res;
	}
public:
	int rob(vector<int>& nums) {
		memo = vector<int>(nums.size(), -1);
		return tryRob(nums, 0);
	}
};

//解法二
//class Solution {
//public:
//	int rob(vector<int>& nums) {
//		if (nums.size() == 0) {
//			return 0;
//		}
//		if (nums.size() == 1) {
//			return nums[0];
//		}
//		vector<int> dp(nums.size(), 0);
//		dp[0] = nums[0];
//		dp[1] = max(nums[0], nums[1]);
//		for (int i = 2; i < nums.size(); i++) {
//			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
//		}
//		return dp[nums.size() - 1];
//	}
//};

int main() {

	vector<int> nums = { 5,2,6,3,1,7 };
	Solution solve;
	printf("%d\n", solve.rob(nums));

	return 0;
}