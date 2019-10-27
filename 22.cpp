//#include<cstdio>
//#include<vector>
//#include<string>
//using namespace std;
//
////void generate(string item,int n,vector<string>& result) {
////	if (item.size() == 2 * n) {
////		result.push_back(item);
////		return;
////	}
////	generate(item + '(', n, result);
////	generate(item + ')', n, result);
////}
//
//class Solution {
//public:
//	vector<string> generateParenthesis(int n) {
//		vector<string> result;
//		generate("", n, n, result);
//		return result;
//	}
//private:
//	void generate(string item, int left, int right, vector<string>& result) {
//		if (left == 0 && right == 0) {
//			result.push_back(item);
//			return;
//		}
//		if (left > 0) {
//			generate(item + '(', left - 1, right, result);
//		}
//		if (left < right) {
//			generate(item + ')', left, right - 1, result);
//		}
//	}
//};
//
//int main() {
//
//	Solution s;
//	vector<string> res = s.generateParenthesis(2);
//	for (int i = 0; i < res.size(); i++) {
//		printf("'%s'\n", res[i].c_str());
//	}
//
//	return 0;
//}