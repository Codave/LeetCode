#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> hash;
		for (auto email : emails) {
			int at = email.find('@');
			string name;
			for (auto c : email.substr(0, at)) {
				if (c == '+') break;
				else if (c != '.') {
					name += c;
				}
			}
			string domain = email.substr(at + 1);
			hash.insert(name + '@' + domain);
		}
		return hash.size();
	}
};

int main() {



	return 0;
}