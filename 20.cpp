//#include<iostream>
//#include<stack>
//#include<string>
//#include<unordered_map>
//using namespace std;
//
//
//// 解法一
////class Solution {
////public:
////	bool isValid(string s) {
////		stack<char> stack;
////		for (int i = 0; i < s.size(); i++) {
////			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
////				stack.push(s[i]);
////			}
////			else {
////				if (stack.size() == 0) {
////					return false;
////				}
////				char c = stack.top();
////				stack.pop();
////
////				char match;
////				if (s[i] == ')') {
////					match = '(';
////				}
////				else if (s[i] == ']') {
////					match = '[';
////				}
////				else {
////					match = '{';
////				}
////				if (c != match) {
////					return false;
////				}
////			}
////		}
////		if (stack.size() != 0) return false;
////		return true;
////	}
////};
//
//// 解法二
//class Solution {
//public:
//	bool isValid(string s) {
//		int n = s.size();
//		if (n % 2 == 1) return false;
//		unordered_map<char, char> mp = {
//			{')','('},
//			{']','['},
//			{'}','{'}
//		};
//		stack<char> stk;
//		for (char ch : s) {
//			if (mp.count(ch)) {
//				if (stk.empty() || stk.top() != mp[ch]) {
//					return false;
//				}
//				stk.pop();
//			}
//			else {
//				stk.push(ch);
//			}
//		}
//		return stk.empty();
//	}
//};
//
//
//
//int main() {
//	string str = "()";
//	int res = Solution().isValid(str);
//	cout << res << endl;
//
//	return 0;
//}