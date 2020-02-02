#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//�ⷨһ
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		//sort(nums.begin(), nums.end());
//		for (int i = 1; i < nums.size(); i++) {
//			if (nums[i - 1] == nums[i]) {
//				nums.erase(nums.begin() + i);
//				i--;
//			}
//		}
//		return nums.size();
//	}
//};

//�ⷨ��
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		for (vector<int>::iterator it = nums.begin() + 1; it != nums.end();) {
			if (*(it - 1) == *it) {
				it = nums.erase(it);
			}
			else {
				it++;
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