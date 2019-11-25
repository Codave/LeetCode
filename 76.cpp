#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

//解法一
//class Solution {
//public:
//	string minWindow(string s, string t) {
//		// 记录最短子串的开始位置和长度
//		int start = 0, minLen = INT_MAX;
//		int left = 0, right = 0;
//
//		unordered_map<char, int> window;
//		unordered_map<char, int> needs;
//		for (char c : t) needs[c]++;
//
//		int match = 0;
//
//		while (right < s.size()) {
//			char c1 = s[right];
//			if (needs.count(c1)) {
//				window[c1]++;
//				if (window[c1] == needs[c1])
//					match++;
//			}
//			right++;
//
//			while (match == needs.size()) {
//				if (right - left < minLen) {
//					// 更新最小子串的位置和长度
//					start = left;
//					minLen = right - left;
//				}
//				char c2 = s[left];
//				if (needs.count(c2)) {
//					window[c2]--;
//					if (window[c2] < needs[c2])
//						match--;
//				}
//				left++;
//			}
//		}
//		return minLen == INT_MAX ?
//			"" : s.substr(start, minLen);
//	}
//};

//解法二
class Solution {
public:
	string minWindow(string s, string t) {
		int count[256] = { 0 };
		for (auto c : t) ++count[c];
		int len = 0, minLength = s.length();
		string res;
		for (int l = 0, r = 0; r < s.length(); ++r) {
			count[s[r]]--;
			if (count[s[r]] >= 0) ++len;
			while (len == t.length()) {
				if (r - l + 1 <= minLength) {
					minLength = r - l + 1;
					res = s.substr(l, r - l + 1);
				}
				count[s[l]]++;
				if (count[s[l]] > 0) --len;
				++l;
			}
		}
		return res;
	}
};

int main() {

	string S = "ADOBECODEBANC";
	string T = "ABC";
	string res = Solution().minWindow(S, T);
	cout << res << endl;

	return 0;
}