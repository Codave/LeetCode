#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		queue<pair<int, int>> q;
		vector<bool> visited(n + 1, false);
		visited[n] = true;
		q.push(make_pair(n, 0));
		while (!q.empty()) {
			int num = q.front().first;
			int step = q.front().second;
			q.pop();
			for (int i = 1; ; i++) {
				int a = num - i * i;
				if (a < 0)	break;
				if (a == 0) return step+1;
				if (!visited[a]) {
					q.push(make_pair(a, step + 1));
					visited[a] = true;
				}
			}
		}
		return 0;
	}
};

int main() {
	
	cout << Solution().numSquares(12) << endl;
	
	return 0;
}