#include <iostream>

using namespace std;

class Solution {
public:
    int  NumberOf1(int n) {
        int count = 0;
        while (n) {
            n &= n - 1;
            ++count;
        }
        return count;
    }
};

int main() {
    Solution s;
    for (int i = 0; i < 100; ++i) 
        cout << i << " : " << s.NumberOf1(i) << endl;
    return 0;
}
