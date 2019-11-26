#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int res=0;
		for (int i = 0; i < points.size(); i++) {
			unordered_map<int, int> record;
			for (int j = 0; j < points.size(); j++) {
				if (j != i) {
					record[dis(points[i], points[j])]++;
				}
			}
			for (unordered_map<int, int>::iterator iter = record.begin(); iter != record.end(); iter++) {
				res += (iter->second) * (iter->second - 1);
			}
		}
		return res;
	}
private:
	int dis(const vector<int>& pa, const vector<int>& pb) {
		return (pa[0] - pb[0]) * (pa[0] - pb[0]) + (pa[1] - pb[1]) * (pa[1] - pb[1]);
	}
};

int main() {

	vector<vector<int>> points = { {0,0},{1,0},{2,0} };
	int res = Solution().numberOfBoomerangs(points);
	cout << res << endl;

	return 0;
}