#include<vector>
#include<cstdio>
using namespace std;

//解法一
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int begin = 0;
		int end = nums.size() - 1;
		while (begin <= end) {
			int mid = (begin + end) / 2;
			if (target == nums[mid]) {
				return mid;
			}
			else if (target < nums[mid]) {
				if (nums[begin] < nums[mid]) {
					if (target >= nums[begin]) {
						end = mid - 1;
					}
					else {
						begin = mid + 1;
					}
				}
				else if (nums[begin] > nums[mid]) {
					end = mid - 1;
				}
				else if (nums[begin] == nums[mid]) {
					begin = mid + 1;
				}
			}
			else if (target > nums[mid]) {
				if (nums[begin] < nums[mid]) {
					begin = mid + 1;
				}
				else if (nums[begin] > nums[mid]) {
					if (target >= nums[begin]) {
						end = mid - 1;
					}
					else {
						begin = mid + 1;
					}
				}
				else if (nums[begin] == nums[mid]) {
					begin = mid + 1;
				}
			}
		}
		return -1;
	}
};

//解法二
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;
		//找到最小值
		int l = 0;
		int r = nums.size() - 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (nums[mid] <= nums.back()) r = mid;
			else l = mid + 1;
		}
		if (target <= nums.back()) r = nums.size() - 1;
		else l = 0, r--;
		while (l < r) {
			int mid = l + r >> 1;
			if (nums[mid] >= target) r = mid;
			else l = mid + 1;
		}
		if (nums[l] == target) return l;
		return -1;
	}
};

int main() {
	int test[] = { 9,12,15,20,1,3,6,7 };
	vector<int> nums;
	Solution solve;
	for (int i = 0; i < 8; i++) {
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 22; i++) {
		printf("%d : %d\n", i, solve.search(nums, i));
	}

	return 0;
}