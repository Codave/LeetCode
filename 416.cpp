#include<iostream>
#include<vector>
using namespace std;

//解法一
//class Solution {
//private:
//	//memo[i][c]表示使用索引为[0...i]的这些元素，是否可以完全填充一个容量为c的背包
//	//-1 表示为未计算； 0 表示不可以填充； 1 表示可以填充
//	vector<vector<int>> memo;
//
//	//使用nums[0...index]，是否可以完全填充一个容量为sum的背包
//	bool tryPartition(const vector<int>& nums, int index, int sum) {
//		if (sum == 0) {
//			return true;
//		}
//		if (sum < 0 || index < 0) {	
//			return false;
//		}
//		if (memo[index][sum] != -1) {
//			return memo[index][sum]==1;  //return memo[index][sum];
//		}
//		memo[index][sum] = (tryPartition(nums, index - 1, sum) || tryPartition(nums, index - 1, sum - nums[index])) ? 1 : 0;
//		return memo[index][sum] == 1;
//	}
//public:
//	bool canPartition(vector<int>& nums) {
//		int sum = 0;
//		for (int i = 0; i < nums.size(); i++) {
//			sum += nums[i];
//		}
//		if (sum % 2 != 0) {
//			return false;
//		}
//		memo = vector<vector<int>>(nums.size(), vector<int>(sum / 2 + 1,-1));
//		return tryPartition(nums, nums.size() - 1, sum / 2);
//	}
//};

//解法二
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}
		if (sum % 2) return false;
		int n = nums.size();
		int C = sum / 2;
		vector<bool> memo(C + 1, false);
		for (int i = 0; i <= C; i++) {
			memo[i] = (nums[0] == i);
		}
		for (int i = 1; i < n; i++) {
			for (int j = C; j >= nums[i]; j--) {
				memo[j] = memo[j] || memo[j - nums[i]];
			}
		}
		return memo[C];
	}
};

int main() {
	vector<int> nums = { 1, 5, 11, 5 };
	cout << Solution().canPartition(nums) << endl;

	return 0;
}