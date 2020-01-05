#include<iostream>
#include<vector>
using namespace std;

//�ⷨһ
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty()) return 0;
		int l = 0;
		int r = nums.size() - 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (nums[mid] <= nums.back()) r = mid;
			else l = mid + 1;
		}
		return nums[r];
	}
};

//�ⷨ��
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.back() > nums[0]) return nums[0];
		int l = 0;
		int r = nums.size() - 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (nums[mid] < nums[0]) r = mid;
			else l = mid + 1;
		}
		return nums[r];
	}
};

int main() {


	return 0;
}
