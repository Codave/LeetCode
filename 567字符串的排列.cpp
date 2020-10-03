//class Solution {
//public:
//	bool checkInclusion(string s1, string s2) {
//		unordered_map<char, int> mp;
//		for (auto c : s1) mp[c]++;
//		int left = 0, r = 0, cnt = s1.size(), n = s2.size();
//		while (r < n) {
//			if (--mp[s2[r++]] >= 0) cnt--;
//			if (cnt == 0) return true;
//			if (r >= s1.size() && mp[s2[left++]]++ >= 0) cnt++;
//		}
//		return false;
//	}
//};