#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<bool> st;
	bool makesquare(vector<int>& nums) {
		int sum = 0;
		for (auto x : nums) sum += x;
		if (!sum || sum % 4) return false;
		sort(nums.rbegin(), nums.rend());
		st = vector<bool>(nums.size());
		return dfs(nums, 0, 0, sum / 4);
	}
	bool dfs(vector<int>& nums, int u, int cur, int target) {
		if (cur == target) u++, cur = 0;
		if (u == 4) return true;
		for (int i = 0; i < nums.size(); i++) {
			if (!st[i] && cur + nums[i] <= target) {
				st[i] = true;
				if (dfs(nums, u, cur + nums[i], target)) return true;
				st[i] = false;
				if (!cur) return false;
				if (cur + nums[i] == target) return false;
				while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
			}
		}
		return false;
	}
};

int main() {
	vector<int> nums = { 3, 3, 3, 3, 4 };
	cout << Solution().makesquare(nums) << endl;
	return 0;
}