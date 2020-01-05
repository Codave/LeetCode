#include<vector>
#include<cstdio>
using namespace std;

//解法一
//class Solution {
//public:
//	vector<int> searchRange(vector<int>& nums, int target) {
//		vector<int> result;
//		result.push_back(left_bound(nums, target));
//		result.push_back(right_bound(nums, target));
//		return result;
//	}
//private:
//	int left_bound(vector<int>& nums, int target) {
//		int begin = 0;
//		int end = nums.size() - 1;
//		while (begin <= end) {
//			int mid = (begin + end) / 2;
//			if (target == nums[mid]) {
//				if (mid == 0 || nums[mid - 1] < target) {
//					return mid;
//				}
//				end = mid - 1;
//			}
//			else if (target < nums[mid]) {
//				end = mid - 1;
//			}
//			else if (target > nums[mid]) {
//				begin = mid + 1;
//			}
//		}
//		return -1;
//	}
//	int right_bound(vector<int>& nums, int target) {
//		int begin = 0;
//		int end = nums.size() - 1;
//		while (begin <= end) {
//			int mid = (begin + end) / 2;
//			if (target == nums[mid]) {
//				if (mid == nums.size()-1 || nums[mid + 1] > target) {
//					return mid;
//				}
//				begin = mid + 1;
//			}
//			else if (target < nums[mid]) {
//				end = mid - 1;
//			}
//			else if (target > nums[mid]) {
//				begin = mid + 1;
//			}
//		}
//		return -1;
//	}
//};

//解法二
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty()) return { -1,-1 };
		int l = 0;
		int r = nums.size()-1;
		while (l < r) {
			int mid = l + r >> 1;
			if (nums[mid] >= target) r = mid;
			else l = mid + 1;
		}
		if (nums[r] != target) return{ -1,-1 };
		int start = r;
		l = 0;
		r = nums.size()-1;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (nums[mid] <= target) l = mid;
			else r = mid - 1;
		}
		return { start,r };
	}
};

int main() {
	int test[] = { 5,7,7,8,8,8,8,10 };
	vector<int> nums;
	Solution solve;
	for (int i = 0; i < 8; i++) {
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 12; i++) {
		vector<int> result = solve.searchRange(nums, i);
		printf("%d:[%d,%d]\n", i, result[0], result[1]);
	}

	return 0;
}