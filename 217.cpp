#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> record;
		for (int i = 0; i < nums.size(); i++) {
			record[nums[i]]++;
			if (record[nums[i]] > 1) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	vector<int> nums = { 1,2,3,1 };
	bool res = Solution().containsDuplicate(nums);
	cout << res << endl;

	return 0;
}