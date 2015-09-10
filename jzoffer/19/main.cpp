#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ans;
        int rows = matrix.size(), cols = rows == 0 ? 0 : matrix[0].size();
        if (rows ==0 || cols == 0) return ans;
        print(matrix, rows, cols, 0, ans);
        return ans;
    }
private:
    void print(vector<vector<int> >& matrix, int& rows, int& cols, int step, vector<int>& ans) {
        if (step == rows / 2 && rows &0x1) {            // 奇数行，最中间一行
            for (int i = step; i < cols - step; ++i)
                ans.push_back(matrix[step][i]);
        } else if (step == cols / 2 && cols & 0x1) {    // 奇数列，最中间一列
            for (int i = step; i < rows - step; ++i)
                ans.push_back(matrix[i][step]);
        } else {
            for (int i = step; i < cols - step; ++i)        // 添加上边
                ans.push_back(matrix[step][i]); 
            for (int i = step + 1; i < rows - step; ++i)    // 添加右边
                ans.push_back(matrix[i][cols - step - 1]);
            for (int i = cols - step - 2; i >= step; --i)   // 添加下边
                ans.push_back(matrix[rows - step - 1][i]);
            for (int i = rows - step - 2; i > step; --i)    // 添加左边
                ans.push_back(matrix[i][step]);

            if (ans.size() < rows * cols)   // 未遍历完毕，继续下一步
                print(matrix, rows, cols, step + 1, ans);
        }
    }
};

int main() {
    vector<vector<int> > matrix;
    vector<int> line1;
    vector<int> line2;
    vector<int> line3;
    vector<int> line4;
    line1.push_back(1); line1.push_back(2); line1.push_back(3);
    line2.push_back(4); line2.push_back(5); line2.push_back(6);
    line3.push_back(7); line3.push_back(8); line3.push_back(9);
    line4.push_back(10); line4.push_back(11); line4.push_back(12);
    matrix.push_back(line1); matrix.push_back(line2); matrix.push_back(line3); matrix.push_back(line4);
    Solution s;
    vector<int> ans = s.printMatrix(matrix);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ",";
    cout << endl;
    return 0;
}
