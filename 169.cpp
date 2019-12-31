#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int cnt = 1;
		int val = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (cnt == 0) {
				val = nums[i];
				cnt = 1;
			}
			else {
				if (val == nums[i]) {
					cnt++;
				}
				else {
					cnt--;
				}
			}
		}
		return val;
	}
};

int main() {
	vector<int> num{ 1,2,3,2,2,2,5,4,2 };
	int res = Solution().majorityElement(num);
	cout << res << endl;

	return 0;
}