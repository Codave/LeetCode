#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> hash;
		hash[0] = 1;
		int res = 0;
		for (int i = 0, sum = 0; i < nums.size(); i++) {
			sum += nums[i];
			res += hash[sum - k];
			hash[sum]++;
		}
		return  res;
	}
};

int main() {
	vector<int> nums({ 1,-1,1,1,1 });
	cout << Solution().subarraySum(nums, 2);

	return 0;
}