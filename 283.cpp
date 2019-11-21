#include<iostream>
#include<vector>
using namespace std;

//解法一
//class Solution {
//public:
//	void moveZeroes(vector<int>& nums) {
//		vector<int> nonZeroElements;
//		int countZero = 0;
//		for (int i = 0; i < nums.size(); i++) {
//			if (nums[i] != 0) {
//				nonZeroElements.push_back(nums[i]);
//			}
//			else if(nums[i]==0){
//				countZero++;
//			}
//		}
//		for (int i = 0; i < countZero; i++) {  //nonZeroElements.insert(nonZeroElement.end(),countZero,0);
//			nonZeroElements.push_back(0);
//		}
//		nums = nonZeroElements;
//	}
//};

//解法二
//class Solution {
//public:
//	void moveZeroes(vector<int>& nums) {
//		vector<int> nonZeroElements;
//		for (int i = 0; i < nums.size(); i++) {
//			if (nums[i] != 0) {
//				nonZeroElements.push_back(nums[i]);
//			}
//		}
//		for (int i = 0; i < nonZeroElements.size(); i++) {
//			nums[i] = nonZeroElements[i];
//		}
//		for (int i = nonZeroElements.size(); i < nums.size(); i++) {
//			nums[i] = 0;
//		}
//	}
//};

//解法三
//class Solution {
//public:
//	void moveZeroes(vector<int>& nums) {
//		int k = 0;  //[0...k)
//		for (int i = 0; i < nums.size(); i++) {
//			if (nums[i]) {
//				nums[k++] = nums[i];
//			}
//		}
//		for (int i = k; i < nums.size(); i++) {
//			nums[i] = 0;
//		}
//	}
//};

//解法四（解法三的优化）
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int k = 0;  //[0...k)
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i]) {
				if (i != k) {
					swap(nums[k++], nums[i]);
				}
				else {
					k++;
				}
				
			}
		}
	}
};

int main() {

	/*vector<int> vec = { 0,1,0,3,12 };
	Solution solve;
	solve.moveZeroes(vec);*/

	int arr[] = { 0,1,0,3,12 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	Solution().moveZeroes(vec);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	
	return 0;
}