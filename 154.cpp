#include<iostream>
#include<vector>
using namespace std;

//�ⷨһ
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

//�ⷨ��
class Solution {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size() - 1;
		if (n < 0) return -1;
		while (n > 0 && nums[n] == nums[0]) n--;
		if (nums[n] >= nums[0]) return nums[0]; //����������ȫ�������������
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