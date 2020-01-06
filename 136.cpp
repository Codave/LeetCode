//解法一
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

//解法二
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_set<int> st;
		for (int num : nums) {
			if (st.count(num)) st.erase(num);
			else st.insert(num);
		}
		return *st.begin();
	}
};

//解法三
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
