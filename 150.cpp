#include<iostream>
#include<string>
#include<set>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		string operators[] = { "+","-","*","/" };
		set<string> myset(operators, operators + 4);
		stack<int> s;
		int a, b;
		for (vector<string>::iterator iter = tokens.begin(); iter != tokens.end(); iter++) {
			if (myset.count(*iter) == 0) {
				s.push(stoi(*iter));
			}
			else {
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
				if (*iter == "+") {
					s.push(b + a);
				}
				else if (*iter == "-") {
					s.push(b - a);
				}
				else if (*iter == "*") {
					s.push(b * a);
				}
				else if (*iter == "/") {
					s.push(b / a);
				}
			}
		}
		return s.top();
	}
};

int main() {
	vector<string> tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	int res = Solution().evalRPN(tokens);
	cout << res << endl;

	return 0;
}