#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int i = 0;
		int j = s.size() - 1;
		while (i < j) {
			if (s[i] != s[j]) {
				swap(s[i], s[j]);
			}
			i++;
			j--;
		}
	}
};

int main() {

	vector<char> str = { 'h','e','l','l','o' };
	Solution().reverseString(str);
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}

	return 0;
}