#include <iostream>

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0) return 0;    

        // 初始化
        int *pUgly = new int[index];
        *pUgly = 1;             // 第1个丑数是1
        int nextUglyIndex = 1;  // 下一个填充的丑数的下标

        // 用于成倍增加的指针
        int *pMultiply2 = pUgly;
        int *pMultiply3 = pUgly;
        int *pMultiply5 = pUgly;

        // 循环填充1-index丑数
        while (nextUglyIndex < index) {
            int minNum = min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
            *(pUgly + nextUglyIndex) = minNum;  // 填充第nextUglyIndex+1个丑数

            // 移动指针
            while (*pMultiply2 * 2 <= minNum)
                ++pMultiply2;
            while (*pMultiply3 * 3 <= minNum)
                ++pMultiply3;
            while (*pMultiply5 * 5 <= minNum)
                ++pMultiply5;

            ++nextUglyIndex;
        }

        int ugly = *(pUgly + index - 1);
        delete(pUgly);
        return ugly;
    }
private:
    int min(int a, int b, int c) {
        int small = a < b ? a : b;
        return small < c ? small : c;
    }
};

int main() {
    Solution s;
    for (int i = 0; i < 100; ++i) {
        cout << i << " : " << s.GetUglyNumber_Solution(i) << endl;
    }
    return 0;
}
