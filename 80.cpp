//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		if (nums.size() == 0) return 0;
//		for (int i = 1; i < nums.size()-1; i++) {
//			if (nums[i - 1] == nums[i] && nums[i] == nums[i+1]) {
//				nums.erase(nums.begin() + i);
//				i--;
//			}
//		}
//		return nums.size();
//	}
//};
//
//int main() {
//	int arr[] = { 1,1,1,2,2,3 };
//	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
//	int res = Solution().removeDuplicates(vec);
//	cout << res << endl;
//
//	return 0;
//}