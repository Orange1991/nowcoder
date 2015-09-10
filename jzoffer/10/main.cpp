#include <iostream>

using namespace std;

class Solution {
public:
    int rectCover(int number) {
        if (number <= 0) return 1;
        if (number <= 2) return number;
        int nums[2] = {1, 2}, p = 3;
        while (p <= number)
            nums[p++ & 0x1 ^ 0x1] = nums[0] + nums[1];
        return nums[p & 0x1];
    }
};

int main() {
    Solution s;
    for (int i = 0; i < 40; ++i)
        cout << s.rectCover(i) << ","; 
    cout << endl;
    return 0;
}
