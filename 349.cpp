#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> record;
		for (int i = 0; i < nums1.size(); i++) {
			record.insert(nums1[i]);
		}
		set<int> resultSet;
		for (int i = 0; i < nums2.size(); i++) {
			if (record.find(nums2[i]) != record.end()) {
				resultSet.insert(nums2[i]);
			}
		}
		vector<int> resultVector;
		for (set<int>::iterator iter = resultSet.begin(); iter != resultSet.end(); iter++) {
			resultVector.push_back(*iter);
		}
		return resultVector;
	}
};

int main() {

	vector<int> nums1 = { 1,2,2,1 };
	vector<int> nums2 = { 2,2 };
	vector<int> res = Solution().intersection(nums1, nums2);
	for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++) {
		cout << *iter << " ";
	}

	return 0;
}