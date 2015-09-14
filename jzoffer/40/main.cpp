#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
        *num1 = 0;
        *num2 = 0;
        int len = data.size();
        if (len <= 1)
            return;

        // 对所有元素求异或
        int num = 0;
        for (int i = 0; i < len; ++i)
            num ^= data[i];

        // 对异或后的值进行处理，只保留最后一个等于1的二进制位
        int division = 0x1;
        while ((division & num) == 0)
            division <<= 1;

        // 遍历所有元素，根据division把元素分为两部分，并进行异或
        for (int i = 0; i < len; ++i)
            if (data[i] & division)
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(6);
    int x, y;
    Solution s;
    s.FindNumsAppearOnce(nums, &x, &y);
    cout << x << "," << y << endl;

    nums.clear();
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(5);

    s.FindNumsAppearOnce(nums, &x, &y);
    cout << x << "," << y << endl;

    nums.clear();
    nums.push_back(1);
    s.FindNumsAppearOnce(nums, &x, &y);
    cout << x << "," << y << endl;
    return 0;
}
