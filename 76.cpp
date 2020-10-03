//#include<iostream>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//
////解法一
//class Solution {
//public:
//	string minWindow(string s, string t) {
//		int count[256] = { 0 };
//		for (auto c : t) ++count[c];
//		int len = 0, minLength = s.length();
//		string res;
//		for (int l = 0, r = 0; r < s.length(); ++r) {
//			count[s[r]]--;
//			if (count[s[r]] >= 0) ++len;
//			while (len == t.length()) {
//				if (r - l + 1 <= minLength) {
//					minLength = r - l + 1;
//					res = s.substr(l, r - l + 1);
//				}
//				count[s[l]]++;
//				if (count[s[l]] > 0) --len;
//				++l;
//			}
//		}
//		return res;
//	}
//};
//
////解法二
//class Solution {
//public:
//	string minWindow(string s, string t) {
//		string res = "";
//		unordered_map<char, int> letterCnt;
//		for (auto c : t) letterCnt[c]++;
//		int left = 0, cnt = 0, minLen = INT_MAX;
//		for (int i = 0; i < s.size(); i++) {
//			if (--letterCnt[s[i]] >= 0) ++cnt;
//			while (cnt == t.size()) {
//				if (minLen > i - left + 1) {
//					minLen = i - left + 1;
//					res = s.substr(left, minLen);
//				}
//				if (++letterCnt[s[left]] > 0) --cnt;
//				left++;
//			}
//		}
//		return res;
//	}
//};
//
//int main() {
//
//	string S = "ADOBECODEBANC";
//	string T = "ABC";
//	string res = Solution().minWindow(S, T);
//	cout << res << endl;
//
//	return 0;
//}