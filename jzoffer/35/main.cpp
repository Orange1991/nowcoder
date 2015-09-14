#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        vector<int> copy;
        copy.insert(copy.end(), data.begin(), data.end());
        return ComputeInverseWhenMerge(copy, 0, copy.size() - 1);
    }
private:
    int ComputeInverseWhenMerge(vector<int>& data, int start, int end) {
        if (start >= end)
            return 0;

        // 统计左右子数组中的逆序数
        int center = (start + end) / 2;
        int inverse = ComputeInverseWhenMerge(data, start, center)
                + ComputeInverseWhenMerge(data, center + 1, end);

        // 归并左右子数组，统计逆序数
        int pLeft = center, pRight = end, pCopy = end - start;
        int *copy = new int[end - start + 1];
        while (pLeft >= start && pRight > center) {
            if (data[pLeft] > data[pRight]) {
                inverse += pRight - center;
                copy[pCopy--] = data[pLeft--];
            } else {
                copy[pCopy--] = data[pRight--];
            }
        }       

        // 拷贝剩余的元素
        while (pLeft >= start)
            copy[pCopy--] = data[pLeft--];
        while (pRight > center)
            copy[pCopy--] = data[pRight--];
        
        // 覆盖原始数据
        pLeft = start;
        pCopy = 0;
        while (pLeft <= end)
            data[pLeft++] = copy[pCopy++];

        delete(copy);

        return inverse;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);
    Solution s;
    cout << s.InversePairs(nums) << endl;
}
