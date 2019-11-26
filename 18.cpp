#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums,int target) {
		vector<vector<int>> result;
		int vecSize = nums.size();
		if (vecSize <= 3) {
			return result;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 3; i++) {
			for (int j = i + 1; j < nums.size() - 2; j++) {
				int intNow = nums[i];
				int intSecond = nums[j];
				
				int negativeNow = target - intNow - intSecond;
				int lo = j + 1;
				int hi = vecSize - 1;
				while (lo < hi) {
					int intLo = nums[lo];
					int intHi = nums[hi];
					if (intLo + intHi == negativeNow) {
						vector<int> tmpVec{ intNow,intSecond,intLo,intHi };
						result.push_back(tmpVec);
						//去重
						while (lo < hi && nums[lo] == intLo) {
							lo++;
						}
						while (lo < hi && nums[hi] == intHi) {
							hi--;
						}
					}
					else if (intLo + intHi < negativeNow) {
						lo++;
					}
					else if (intLo + intHi > negativeNow) {
						hi--;
					}
				}
				//去重
				while (j + 1 < nums.size() - 2 && nums[j] == nums[j + 1]) {
					j++;
				}
			}
			//去重
			while (i + 1 < nums.size() - 3 && nums[i] == nums[i + 1]) {
				i++;
			}
		}
		return result;
	}
};

int main() {

	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	vector<vector<int>> res = Solution().fourSum(nums, 0);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}