#include<iostream>
#include<vector>
using namespace std;

//解法一
//class Solution {
//public:
//	int searchInsert(vector<int>& nums, int target) {
//		int index = -1;
//		int begin = 0;
//		int end = nums.size() - 1;
//		while (index == -1) {
//			int mid = (begin + end) / 2;
//			if (target == nums[mid]) {
//				index = mid;
//			}
//			else if (target < nums[mid]) {
//				if (mid == 0 || target > nums[mid - 1]) {
//					index = mid;
//				}
//				end = mid - 1;
//			}
//			else if (target > nums[mid]) {
//				if (mid == nums.size() - 1 || target < nums[mid + 1]) {
//					index = mid + 1;
//				}
//				begin = mid + 1;
//			}
//		}
//		return index;
//	}
//};

//解法二
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty() || nums.back() < target) return nums.size();
		int l = 0;
		int r = nums.size() - 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (nums[mid] < target) l = mid + 1;
			else r = mid;
		}
		return r;
	}
};

//解法三
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty() || nums.back() < target) return nums.size();
		int l = 0;
		int r = nums.size() - 1;
		while (l < r) {
			int mid = l + r +1 >> 1;
			if (nums[mid] >= target) l = mid;
			else r = mid - 1;
		}
		return r;
	}
};

int main() {
	int test[] = { 1,3,5,6 };
	vector<int> nums;
	Solution solve;
	for (int i = 0; i < 4; i++) {
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 8; i++) {
		printf("i=%d index=%d\n", i, solve.searchInsert(nums, i));
	}

	return 0;
}