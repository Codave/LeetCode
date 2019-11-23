#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zero = -1; //nums[0...zero] == 0
		int two = nums.size();	//nums[two..n-1] == 2
		for (int i = 0; i < two;) {
			if (nums[i] == 1) {
				i++;
			}
			else if (nums[i] == 2) {
				swap(nums[i], nums[--two]);
			}
			else {
				assert(nums[i] == 0);
				swap(nums[++zero], nums[i++]);
			}
		}
	}
};

int main() {
	int arr[] = { 2,0,2,1,1,0 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	Solution().sortColors(vec);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}

	return 0;
}