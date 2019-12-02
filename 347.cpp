#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> freq;	//统计每个元素出现的频率
		for (int i = 0; i < nums.size(); i++) {
			freq[nums[i]]++;
		}
		//pair<int,int>  (频率，元素)
		priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		for (unordered_map<int, int>::iterator iter = freq.begin(); iter != freq.end(); iter++) {
			if (pq.size() == k) {
				if (iter->second > pq.top().first) {
					pq.pop();
					pq.push(make_pair(iter->second, iter->first));
				}
			}
			else {
				pq.push(make_pair(iter->second, iter->first));
			}
		}
		vector<int> res;
		while (!pq.empty()) {
			res.push_back(pq.top().second);
			pq.pop();
		}
		return res;
	}
};

int main() {

	vector<int> nums = { 1,1,1,2,2,3 };
	int k = 2;
	vector<int> res = Solution().topKFrequent(nums, k);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}