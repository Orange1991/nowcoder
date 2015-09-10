#include <iostream>

using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        if (number <= 0) return 0;
        int ans = 1, i = 1;
        while (i++ < number) ans *= 2;
        return ans;
    }
};

int main() {
    Solution s;
    for (int i = 0; i < 20; ++i) 
        cout << s.jumpFloorII(i) << ",";
    cout << endl;
}
