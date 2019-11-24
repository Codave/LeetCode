#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int l = 0, r = -1; //nums[l...r]Îª»¬¶¯´°¿Ú
		int sum = 0;
		int res = nums.size() + 1;
		while (l < nums.size()) {
			if (r+1 < nums.size() && sum < s) {
				r++;
				sum += nums[r];
			}
			else {
				sum -= nums[l];
				l++;
			}
			if (sum >= s) {
				res = min(res, r - l + 1);
			}
		}
		if (res == nums.size() + 1) return 0;

		return res;
	}
};

int main() {

	vector<int> nums = { 2,3,1,2,4,3 };
	Solution slove;
	int res = slove.minSubArrayLen(7, nums);
	cout << res << endl;

	return 0;
}