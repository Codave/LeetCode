#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	int removeElement(vector<int>& nums, int val) {
//		for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
//			if (*it == val) {
//				it = nums.erase(it);  //���Կ���
//			}
//			else {
//				it++;
//			}
//		}
//		return nums.size();
//	}
//};

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == val) {
				nums.erase(nums.begin() + i);
				i--;	//����erase���������ڲ�������
			}
		}
		return nums.size();
	}
};

int main() {
	int arr[] = { 3,2,2,3 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	int res = Solution().removeElement(vec,3);
	cout << res << endl;

	return 0;
}