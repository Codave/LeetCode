#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		int i = 0;
		int j = s.size() - 1;
		string aux = "aeiouAEIOU";
		while (i < j) {
			while (i < j && (aux.find(s[i]) == string::npos)) i++;
			while (i < j && (aux.find(s[j]) == string::npos)) j--;
			swap(s[i++], s[j--]);
		}
		return s;
	}
};

int main() {
	string str = "hello";
	string res = Solution().reverseVowels(str);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}