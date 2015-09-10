#include <iostream>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        if (n < 2) return n;
        int op[2], index = 2;
        op[0] = 0; 
        op[1] = 1;
        while (index <= n) {
            op[index & 0x1] = op[0] + op[1];
            index++;
        }
        return op[index & 0x1 ^ 0x1];
    }
};

int main() {
    Solution s;
    for (int i = 0; i < 40; ++i)
        cout << s.Fibonacci(i) << ",";
    cout << endl;
    return 0;
}
