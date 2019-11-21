#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		//sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i - 1] == nums[i]) {
				nums.erase(nums.begin() + i);
				i--;
			}
		}
		return nums.size();
	}
};

int main() {
	int arr[] = { 1,1,2 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	int res = Solution().removeDuplicates(vec);
	cout << res << endl;

	return 0;
}