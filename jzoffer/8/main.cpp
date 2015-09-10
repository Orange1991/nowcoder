#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 0) return 0;
        if (number <= 2) return number;
        int nums[2] = {1, 2};
        int p = 3;
        while (p <= number)
            nums[p++ & 0x1 ^ 0x1] = nums[0] + nums[1];
        return nums[number & 0x1 ^ 0x1];
    }
};

int main() {
    Solution s;
    for (int i = 0; i < 40; ++i)
        cout << s.jumpFloor(i) << ",";
    return 0;    
}
