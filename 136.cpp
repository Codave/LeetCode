//�ⷨһ
class Solution {
public:
	int singleNumber(vector<int>& data) {
		unordered_map<int, int> umap;
		for (int i = 0; i < data.size(); i++) {
			umap[data[i]]++;
		}
		for (int i = 0; i < data.size(); i++) {
			if (umap[data[i]] == 1) {
				return data[i];
			}
		}
		return 0;
	}
};

//�ⷨ��
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto x : nums) {
			res ^= x;
		}
		return res;
	}
};
