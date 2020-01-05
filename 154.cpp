#include<iostream>
#include<vector>
using namespace std;

//解法一
class Solution {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size() - 1;
		if (n < 0) return -1;
		while (n > 0 && nums[n] == nums[0]) n--;
		if (nums[n] >= nums[0]) return nums[0];
		int l = 0, r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if (nums[mid] < nums[0]) r = mid;
			else l = mid + 1;
		}
		return nums[r];
	}
};

//解法二
class Solution {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size() - 1;
		if (n < 0) return -1;
		while (n > 0 && nums[n] == nums[0]) n--;
		if (nums[n] >= nums[0]) return nums[0]; //处理数组完全单调的特殊情况
		int l = 0, r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if (nums[mid] <= nums[n]) r = mid;
			else l = mid + 1;
		}
		return nums[r];
	}
};

int main() {


	return 0;
}