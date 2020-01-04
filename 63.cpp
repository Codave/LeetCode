#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(); //����
		int n = obstacleGrid[0].size();//����
		vector<vector<long>> p(m, vector<long>(n, 0));
		//��һ�и�ֵ 
		int k = 0;
		while (k < m && obstacleGrid[k][0] != 1)
			p[k++][0] = 1;
		//����������ϰ���������������ֵ��Ϊ0
		while (k < m)
			p[k++][0] = 0;

		//��һ�и�ֵ
		k = 0;
		while (k < n && obstacleGrid[0][k] != 1)
			p[0][k++] = 1;
		while (k < n)
			p[0][k++] = 0;

		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) //��������ϰ�����λ�õ�ֵΪ0
					p[i][j] = 0;
				else
					p[i][j] = p[i - 1][j] + p[i][j - 1];
			}
		return p[m - 1][n - 1];
	}
};

int main() {
	vector<vector<int>> num = { {0, 0, 0} ,{0, 1, 0 },{0, 0, 0} };
	Solution().uniquePathsWithObstacles(num);
	

	return 0;
}