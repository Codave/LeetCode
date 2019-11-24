#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int i = 0;
		int j = height.size() - 1;
		int maxArea = 0;
		while (i < j) {
			int nowArea = (j - i) * min(height[i], height[j]);
			if (nowArea > maxArea){
				maxArea = nowArea;
			}
			if (height[i] <= height[j]) {
				i++;
			}
			else if (height[i] > height[j]) {
				j--;
			}
		}
		return maxArea;
	}
};

int main() {

	vector<int> height = { 1,8,6,2,5,4,8,3,7 };

	Solution slove;
	int res = slove.maxArea(height);
	cout << res << endl;

	return 0;
}