#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		int vecSize = nums.size();
		if (vecSize <= 2) {
			return result;
		}
		sort(nums.begin(), nums.end());
		for (int index = 0; index < nums.size() - 2; index++) {
			int intNow = nums[index];
			if (intNow > 0) {
				break;
			}
			int negativeNow = 0 - intNow;
			int lo = index + 1;
			int hi = vecSize - 1;
			while (lo < hi) {
				int intLo = nums[lo];
				int intHi = nums[hi];
				if (intLo + intHi == negativeNow) {
					vector<int> tmpVec{ intNow,intLo,intHi };
					result.push_back(tmpVec);
					//去重
					while (lo < hi && nums[lo] == intLo) {
						lo++;
					}
					while (lo < hi && nums[hi] == intHi) {
						hi--;
					}
				}
				else if (intLo + intHi < negativeNow){
					lo++;
				}
				else if (intLo + intHi > negativeNow) {
					hi--;
				}
			}
			//去重
			while (index + 1 < nums.size() - 1 && nums[index] == nums[index + 1]) {
				index++;
			}
		}
		return result;
	}
};

int main() {

	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> res = Solution().threeSum(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}