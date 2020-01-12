#include<iostream>
#include<string>
#include<sstream>
using namespace std;

//解法一
//class Solution {
//public:
//	string reverseWords(string s) {
//		int k = 0;
//		for (int i = 0; i < s.size(); i++) {
//			while (i < s.size() && s[i] == ' ') i++;
//			if (i == s.size()) break;
//			int j = i;
//			while (j < s.size() && s[j] != ' ') j++;
//			reverse(s.begin() + i, s.begin() + j);
//			if (k) s[k++] = ' ';
//			while (i < j) s[k++] = s[i++];
//		}
//		s.erase(s.begin() + k, s.end());
//		reverse(s.begin(), s.end());
//		return s;
//	}
//};

//解法二
//class Solution {
//public:
//	void reverseWords(string& s) {
//		int index = 0, n = s.size();
//		reverse(s.begin(), s.end());
//		for (int i = 0; i < n; i++) {
//			if (s[i] != ' ') {
//				if (index != 0) s[index++] = ' ';
//				int j = i;
//				while (j < n && s[j] != ' ') s[index++] = s[j++];
//				reverse(s.begin() + index - (j - i), s.begin() + index);
//				i = j;
//			}
//		}
//		s.resize(index);
//	}
//};

//解法三
class Solution {
public:
	string reverseWords(string s) {
		istringstream is(s);
		string tmp;
		is >> s;
		while (is >> tmp) {
			s = tmp + " " + s;
		}
		if (!s.empty() && s[0] == ' ') s = "";
		return s;
	}
};

int main() {

	string str = "  hello world!  ";
	Solution().reverseWords(str);

	return 0;
}