class Solution {
public:
	int hIndex(vector<int>& nums) {
		int l = 0;
		int r = nums.size();
		while (l < r) {
			int mid = l + (r - l + 1 >> 1);
			if (nums[nums.size() - mid] >= mid) l = mid;
			else r = mid - 1;
		}
		return r;
	}
};