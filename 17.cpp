#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
	const string letterMap[10] = {
		" ",	//0
		"",		//1
		"abc",	//2
		"def",	//3
		"ghi",	//4
		"jkl",	//5
		"mno",	//6
		"pqrs",	//7
		"tuv",	//8
		"wxyz"	//9
	};
	vector<string> res;
	void findCombination(const string& digits, int index, const string& s) {
		//cout << index << ':' << s << endl;
		if (index == digits.size()) {
			res.push_back(s);
			//cout << "get " << s << ",return" << endl;
			return;
		}
		char c = digits[index];
		string letters = letterMap[c - '0'];
		for (int i = 0; i < letters.size(); i++) {
			//cout << "digits[" << index << "]=" << c << ",use " << letters[i] << endl;
			findCombination(digits, index + 1, s + letters[i]);
		}
		//cout << "digits[" << index << "]=" << c << " complete,return" << endl;
		return;
	}
public:
	vector<string> letterCombinations(string digits) {
		res.clear();
		if (digits.size() == 0) return res;
		findCombination(digits, 0, "");
		return res;
	}
};

int main() {

	string str = "23";
	vector<string> res = Solution().letterCombinations(str);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}