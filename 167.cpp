#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int l = 0;
		int r = numbers.size() - 1;
		while (l < r) {
			if (numbers[l] + numbers[r] == target) {
				int res[2] = { l + 1,r + 1 };
				return vector<int>(res, res + 2);
			}
			else if (numbers[l] + numbers[r] < target) {
				l++;
			}
			else {
				r--;
			}
		}
	}
};

int main() {
	vector<int> nums = { 2,7,11,15 };
	int target = 9;
	Solution solve;
	vector<int> res = solve.twoSum(nums, target);
	cout << res[0] << "," << res[1] << endl;
	
	return 0;
}