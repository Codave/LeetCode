//#include<iostream>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
////解法一
//class Solution {
//public:
//	vector<int> findAnagrams(string s, string t) {
//		if (s.empty()) return {};
//		vector<int> res, m(123, 0);	// z的ASCII码为122
//		int left = 0, right, cnt = t.size(), n = s.size();
//		for (char c : s) ++m[c];
//		while (right < n) {
//			if (m[s[right++]]-- >= 1) --cnt;
//			if (cnt == 0) res.push_back(left);
//			//if (right - left = t.size() && m[s[left++]]++ >= 0) ++cnt;
//			if (right >= t.size() && m[s[left++]]++ >= 0) ++cnt;
//		}
//		return res;
//	}
//};
//
//int main() {
//
//	string S = "cbaebabacd" ;
//	string T = "abc";
//	vector<int> res = Solution().findAnagrams(S, T);
//	for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++) {
//		cout << *iter << " ";
//	}
//
//	return 0;
//}