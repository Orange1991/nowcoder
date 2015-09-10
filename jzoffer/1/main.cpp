#include <iostream>
#include <vector>

class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        int rows = array.size(), cols = rows == 0 ? 0 : array[0].size(), i = 0, j = cols - 1;
        if (rows == 0 || cols == 0) return false;
        while (i < rows && j > -1) {
            if (array[i][j] == target) return true;
            else if (array[i][j] > target) --j;
            else ++i;
        }
        return false;
    }
};

int main() {
    return 0;
}
