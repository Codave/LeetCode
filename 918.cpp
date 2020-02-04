#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxSubarraySumCircular(vector<int>& A) {
		int n = A.size();
		for (int i = 0; i < n; i++) {
			A.push_back(A[i]);
		}
		vector<int> sum(n * 2 + 1);
		for (int i = 1; i <= n * 2; i++) {
			sum[i] = sum[i - 1] + A[i - 1];  //sum[i]表示数组A的下标i的前缀和
		}
		int res = INT_MIN;
		deque<int> q;
		q.push_back(0);
		for (int i = 1; i <= n * 2; i++) {
			if (q.size() && q.front() + n < i) q.pop_front();
			if (q.size()) res = max(res, sum[i] - sum[q.front()]);
			while (q.size() && sum[q.back()] >= sum[i]) q.pop_back();
			q.push_back(i);
		}
		return res;
	}
};

int main() {
	vector<int> nums({ 1,-2,3,-2 });
	int res = Solution().maxSubarraySumCircular(nums);

	return 0;
}