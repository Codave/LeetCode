#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int result = 0;
		int gap = INT_MAX;
		int vecSize = nums.size();
		if (vecSize <= 2) {
			return result;
		}
		sort(nums.begin(), nums.end());
		for (int index = 0; index < nums.size() - 2; index++) {
			int intNow = nums[index];
			
			int negativeNow = target - intNow;
			int lo = index + 1;
			int hi = vecSize - 1;
			while (lo < hi) {
				int intLo = nums[lo];
				int intHi = nums[hi];
				if (intLo + intHi == negativeNow) {
					return target;
				}
				else if (intLo + intHi < negativeNow) {
					int tmpGap = negativeNow - (intLo + intHi);
					//更新gap
					if (tmpGap < gap) {
						gap = tmpGap;
						result = intNow + intHi + intLo;
					}
					while (lo < vecSize && nums[lo] == intLo) {
						lo++;
					}
				}
				else if (intLo + intHi > negativeNow){
					int tmpGap = (intLo + intHi) - negativeNow;
					//更新gap
					if (tmpGap < gap) {
						gap = tmpGap;
						result = intNow + intHi + intLo;
					}
					while (hi >= 0 && nums[hi] == intHi) {
						hi--;
					}
				}
			}
			//去重
			while (index + 1 < nums.size() - 2 && nums[index] == nums[index + 1]) {
				index++;
			}
		}
		return result;
	}
};

int main() {

	vector<int> nums = { -1,2,1,-4 };
	int res = Solution().threeSumClosest(nums,1);
	cout << res << endl;

	return 0;
}