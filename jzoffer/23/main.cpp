#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if (len <= 0) return false;
        return verifySubSequenceOfBST(sequence, 0, len - 1);
    }
private:
    bool verifySubSequenceOfBST(vector<int>& sequence, int start, int end) {
        if (end - start <= 1)   // 子序列不多于两个元素，一定是某个BST子数
            return true;
        int rootValue = sequence[end];
        int rightStart, rightEnd;
        if (sequence[end - 1] > rootValue) {    // 找到比根元素大的元素
            rightStart = end - 1, rightEnd = end - 1;
            while (rightStart > start && sequence[rightStart - 1] > rootValue)
                --rightStart;
            // 验证右子树
            if (!verifySubSequenceOfBST(sequence, rightStart, rightEnd))
                return false;
        } else {    // 没有比根元素大的元素
            rightStart = end;
        }

        if (rightStart == start)    // 没有比根元素小的元素
            return true;
        
        // 找到比根元素小的元素
        int leftEnd = rightStart - 1, leftStart = leftEnd;
        while (leftStart > start && sequence[leftStart - 1] < rootValue)
            --leftStart;
        if (leftStart != start)     // 左子树中出现比根元素大的元素
            return false;
        // 验证左子树
        return verifySubSequenceOfBST(sequence, leftStart, leftEnd);
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(8);
    nums.push_back(6);
    nums.push_back(12);
    nums.push_back(11);
    nums.push_back(15);
    nums.push_back(14);
    nums.push_back(13);
    nums.push_back(17);
    nums.push_back(19);
    nums.push_back(20);
    nums.push_back(18);
    nums.push_back(16);
    nums.push_back(10);
    Solution s;
    if (s.VerifySquenceOfBST(nums))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
